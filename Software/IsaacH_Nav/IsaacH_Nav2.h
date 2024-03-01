#include <Adafruit_Sensor_Calibration.h>
#include <Adafruit_AHRS.h>

#include <Ultrasonic.h> //CHANGE
#include <Adafruit_VL53L0X.h>  //CHANGE

#include <GyverOLED.h>
#include <QTRSensors.h>

//Objects
QTRSensors qtr;
QTRSensors qtr_back;
Adafruit_Sensor *accelerometer, *gyroscope, *magnetometer;
GyverOLED<SSH1106_128x64> oled;
Adafruit_Mahony filter;

#include "LSM6DS_LIS3MDL.h"


//Pulls calibration data from EEPROM
#if defined(ADAFRUIT_SENSOR_CALIBRATION_USE_EEPROM)
  Adafruit_Sensor_Calibration_EEPROM cal;
#else
  Adafruit_Sensor_Calibration_SDFat cal;
#endif

#define FILTER_UPDATE_RATE_HZ 100
#define PRINT_EVERY_N_UPDATES 10
//#define AHRS_DEBUG_OUTPUT

uint32_t timestamp;
uint32_t u32_LineFollowingTime = 0;

//Line Following variables
const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];
uint16_t backSensorValues[SensorCount];

//Location/Position objects
Ultrasonic ultrasonicFront(8); //CHANGE
Ultrasonic ultrasonicBack(9); //CHANGE
Ultrasonic ultrasonicRight(10); //CHANGE
Ultrasonic ultrasonicLeft(11); //CHANGE

//Object Detection objects
Adafruit_VL53L0X sensor1; //CHANGE
Adafruit_VL53L0X sensor2; //CHANGE
Adafruit_VL53L0X sensor3; //CHANGE
Adafruit_VL53L0X sensor4; //CHANGE
Adafruit_VL53L0X sensor5; //CHANGE
Adafruit_VL53L0X sensor6; //CHANGE
Adafruit_VL53L0X sensor7; //CHANGE
Adafruit_VL53L0X sensor8; //CHANGE

//***********CHANGE*************//
//Define Variables for Object Detection Sensors
typedef struct {
  Adafruit_VL53L0X *psensor; // pointer to object
  TwoWire *pwire;
  int id;            // IIC id number for the sensor
  int shutdown_pin;  // which pin for shutdown;
  int interrupt_pin; // which pin to use for interrupts.
  Adafruit_VL53L0X::VL53L0X_Sense_config_t sensor_config; // options for how to use the sensor
  uint16_t range;        // range value used in continuous mode stuff.
  uint8_t sensor_status; // status from last ranging in continuous.
} sensorList_t;

//**********CHANGE**************//
// Setup for 8 sensors by defining information for each sensor in a 'sensors' array. Include
// a separate line of information for each sensor
sensorList_t sensors[] = {
  // For 'sensor1', define the IIC accress as hexadecimal value 0x30. Assign digital pin #4 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #5 to the sensor's INTERRUPT pin.
  {&sensor1, &Wire, 0x30, 4, 5, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},

  // For 'sensor2', define the IIC accress as hexadecimal value 0x31. Assign digital pin #6 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #7 to the sensor's INTERRUPT pin.
  {&sensor2, &Wire, 0x31, 6, 7, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},

  
  // For 'sensor3', define the IIC accress as hexadecimal value 0x32. Assign digital pin #22 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #23 to the sensor's INTERRUPT pin.
  {&sensor3, &Wire, 0x32, 2, 3, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},
  
  // For 'sensor4', define the IIC accress as hexadecimal value 0x33. Assign digital pin #24 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #25 to the sensor's INTERRUPT pin.
  {&sensor4, &Wire, 0x33, 29, 30, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},

  // For 'sensor5', define the IIC accress as hexadecimal value 0x34. Assign digital pin #26 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #27 to the sensor's INTERRUPT pin.
  {&sensor5, &Wire, 0x34, 31, 32, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},

  // For 'sensor6', define the IIC accress as hexadecimal value 0x35. Assign digital pin #28 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #29 to the sensor's INTERRUPT pin.
  {&sensor6, &Wire, 0x35, 33, 34, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},

  // For 'sensor7', define the IIC accress as hexadecimal value 0x36. Assign digital pin #30 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #31 to the sensor's INTERRUPT pin.
  {&sensor7, &Wire, 0x36, 35, 36, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},
  
  // For 'sensor8', define the IIC accress as hexadecimal value 0x37. Assign digital pin #32 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #25 to the sensor's INTERRUPT pin.
  {&sensor8, &Wire, 0x37, 37, 38, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0}
  
};

//Object Detection Variables
const int COUNT_SENSORS = sizeof(sensors) / sizeof(sensors[0]); //CHANGE
uint16_t objectDetectRanges_mm[COUNT_SENSORS]; //CHANGE


void setup_LineFollowing();
void setup_Orientation();
void setup_OLED();
void run_LineFollowing();
void run_OLED();
void run_Orientation();
void drawBattery(byte);
void charging();
void run_Location(); //CHANGE
void initialize_ObjDetectSensors(); //CHANGE
void setup_ObjectDetection(); //CHANGE
void run_ObjectDetection(); //CHANGE

struct Packet{
  uint16_t lineFollowing;
  uint32_t locationFront; //CHANGE
  uint32_t locationBack; //CHANGE
  uint32_t locationRight; //CHANGE
  uint32_t locationLeft; //CHANGE
  uint16_t objectDetectionSensors[COUNT_SENSORS]; //CHANGE
  float heading;
  float roll;
  float pitch;
  float qw;
  float qx;
  float qy; 
  float qz;
};

Packet packet;

//OLED variables
bool b_battery_charging = 1;
uint8_t voltage = 6;
uint8_t percent = 0;
const uint8_t techLogo [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0x7C, 0x3C, 0x7C, 0xFC, 0x3C, 0x1C, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0x3C, 0xFC, 0x7C, 0x3C, 0x7C, 0xFC, 0xFC, 0xFC, 0xFC, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x1F, 0x1F, 0x1F, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x01, 0x00,
0x00, 0x00, 0x04, 0x0E, 0x07, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF1, 0xE3, 0xF7, 0xFC, 0xF0, 0xE0, 0xC0,
0xC0, 0xC0, 0xC0, 0xE0, 0xF0, 0xFC, 0xF7, 0xE3, 0xF1, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/*
*Function Name: setup_LineFollowing
*Parameters: None
*Returns: void
*Description: Initializes sensor pins and emitter pin. Calibrates the sensor for 10 seconds 
* to read the reflectance of the line and the background color. 
*/
void setup_LineFollowing(){
    // configure the sensors
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){28, 27, 26, 25, 24, 23}, SensorCount);
  qtr.setEmitterPin(22);

  qtr_back.setTypeRC();
  qtr_back.setSensorPins((const uint8_t[]){48, 49, 50 , 51, 52, 53}, SensorCount);
  qtr_back.setEmitterPin(47);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

  // 2.5 ms RC read timeout (default) * 10 reads per calibrate() call
  // = ~25 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
    qtr_back.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  /*for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();*/
  
  // print the calibration maximum values measured when emitters were on
  /*for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();*/
  delay(2000);
}

/*
*Function Name: setup_Orientation
*Parameters: None
*Returns: void
*Description: Calibrates the magnetometer and the accelerometer.
* Initializes the accelerometer, gyroscope, and magnetometer.
*/
void setup_Orientation(){
  if (!cal.begin()) {
    Serial.println("Failed to initialize calibration helper");
  }

  if (!init_sensors()) {
    Serial.println("Failed to find sensors");
    while (1) delay(10);
  }
  
  /*
  accelerometer->printSensorDetails();
  gyroscope->printSensorDetails();
  magnetometer->printSensorDetails();
  */

  setup_sensors();
  filter.begin(FILTER_UPDATE_RATE_HZ);
  timestamp = millis();

  Wire.setClock(400000); // 400KHz
}

void run_LineFollowing(){
  uint32_t u32_currentMillis = millis();
  if((u32_currentMillis - u32_LineFollowingTime)>=250){
    uint16_t position = qtr.readLineBlack(sensorValues);
    uint16_t position_back = qtr_back.readLineBlack(backSensorValues);
    // print the sensor values as numbers from 0 to 1000, where 0 means maximum
    // reflectance and 1000 means minimum reflectance, followed by the line
    // position
    /*for (uint8_t i = 0; i < SensorCount; i++)
    {
      Serial.print(sensorValues[i]);
      Serial.print('\t');
    }*/
    packet.lineFollowing = position; 
  }
}

void run_OLED(){
  if(b_battery_charging){
    charging();
  }
  else{
    percent = voltage*100/12;
    oled.setCursorXY(0, 0);
    drawBattery(percent);
    oled.setCursorXY(20,0);

    oled.print(percent);
    oled.print("%");
    oled.drawBitmap(0, 0, techLogo, 128, 64);
    oled.update();
  }
}
void drawBattery(byte percent) {
  oled.drawByte(0b00111100);  // пипка
  oled.drawByte(0b00111100);
  oled.drawByte(0b11111111);  // стенка
  
  for (byte i = 0; i < 100 / 8; i++) {
    if (i < (100 - percent) / 8) oled.drawByte(0b10000001);
    else oled.drawByte(0b11111111);
  }
    oled.drawByte(0b11111111);  //Draw left part of battery
}

void charging(){
//Battery Fill Forward
  for (byte i = 0; i < 100; i += 5) {
    oled.clear();
    oled.setCursorXY(0, 0);
    drawBattery(i);
    oled.update();
    delay(50);
  }
  //Battery Fill Backward
  for (int i = 100; i > 0; i -= 5) {
    oled.clear();
    oled.setCursorXY(0, 0);
    drawBattery(i);
    oled.update();
    delay(50);
  }
}

void run_Orientation(){
  float roll, pitch, heading;
  float gx, gy, gz;
  static uint8_t counter = 0;

  if ((millis() - timestamp) < (1000 / FILTER_UPDATE_RATE_HZ)) {
    return;
  }
  timestamp = millis();
  // Read the motion sensors
  sensors_event_t accel, gyro, mag;
  accelerometer->getEvent(&accel);
  gyroscope->getEvent(&gyro);
  magnetometer->getEvent(&mag);


  cal.calibrate(mag);
  cal.calibrate(accel);
  cal.calibrate(gyro);
  // Gyroscope needs to be converted from Rad/s to Degree/s
  // the rest are not unit-important
  gx = gyro.gyro.x * SENSORS_RADS_TO_DPS;
  gy = gyro.gyro.y * SENSORS_RADS_TO_DPS;
  gz = gyro.gyro.z * SENSORS_RADS_TO_DPS;

  // Update the SensorFusion filter
  filter.update(gx, gy, gz, 
                accel.acceleration.x, accel.acceleration.y, accel.acceleration.z, 
                mag.magnetic.x, mag.magnetic.y, mag.magnetic.z);
/*#if defined(AHRS_DEBUG_OUTPUT)
  Serial.print("Update took "); Serial.print(millis()-timestamp); Serial.println(" ms");
#endif*/

  // only print the calculated output once in a while
  if (counter++ <= PRINT_EVERY_N_UPDATES) {
    return;
  }
  // reset the counter
  counter = 0;

/*#if defined(AHRS_DEBUG_OUTPUT)
  Serial.print("Raw: ");
  Serial.print(accel.acceleration.x, 4); Serial.print(", ");
  Serial.print(accel.acceleration.y, 4); Serial.print(", ");
  Serial.print(accel.acceleration.z, 4); Serial.print(", ");
  Serial.print(gx, 4); Serial.print(", ");
  Serial.print(gy, 4); Serial.print(", ");
  Serial.print(gz, 4); Serial.print(", ");
  Serial.print(mag.magnetic.x, 4); Serial.print(", ");
  Serial.print(mag.magnetic.y, 4); Serial.print(", ");
  Serial.print(mag.magnetic.z, 4); Serial.println("");
#endif
*/
  // print the heading, pitch and roll
  roll = filter.getRoll();
  pitch = filter.getPitch();
  heading = filter.getYaw();
  packet.heading = heading;
  packet.pitch = pitch;
  packet.roll = roll;
  /*Serial.print("Orientation: ");
  Serial.print(heading);
  Serial.print(", ");
  Serial.print(pitch);
  Serial.print(", ");
  Serial.println(roll);
*/
  float qw, qx, qy, qz;
  filter.getQuaternion(&qw, &qx, &qy, &qz);
  packet.qw = qw;
  //Serial.println(qw,4);
  packet.qx = qx;
  //Serial.println(qx,4);
  packet.qy = qy;
  //Serial.println(qy,4);
  packet.qz = qz;
  //Serial.println(qz,4);
  //Serial.println("Made it to the end");
  /*Serial.print("Quaternion: ");
  Serial.print(qw, 4);
  Serial.print(", ");
  Serial.print(qx, 4);
  Serial.print(", ");
  Serial.print(qy, 4);
  Serial.print(", ");
  Serial.println(qz, 4);  */
 /* 
#if defined(AHRS_DEBUG_OUTPUT)
  Serial.print("Took "); Serial.print(millis()-timestamp); Serial.println(" ms");
#endif*/
}

/*
*Function Name: run_Location
*Parameters: None
*Returns: void
*Description: Starts the Ultrasonic to get distance (mm)
*/

void run_Location(){
  packet.locationFront = ultrasonicFront.MeasureInMillimeters();
  packet.locationBack = ultrasonicBack.MeasureInMillimeters();
  packet.locationRight = ultrasonicRight.MeasureInMillimeters();
  packet.locationLeft = ultrasonicLeft.MeasureInMillimeters();
  //delay(60);
}

/*
*Function Name: initialize_ObjDetectSensors
*Parameters: None
*Returns: void
*Description: Initialize the Object Detection Sensors
*/

void initialize_ObjDetectSensors(){
  bool found_any_sensors = false;
  // Set all shutdown pins low to shutdown sensors
  for (int i = 0; i < COUNT_SENSORS; i++)
    digitalWrite(sensors[i].shutdown_pin, LOW);
  delay(10);

  for (int i = 0; i < COUNT_SENSORS; i++) {
    // one by one enable sensors and set their ID
    digitalWrite(sensors[i].shutdown_pin, HIGH);
    delay(10); // give time to wake up.
    if (sensors[i].psensor->begin(sensors[i].id, false, sensors[i].pwire,
                                  sensors[i].sensor_config)) {
      found_any_sensors = true;
    }
  }
  if (!found_any_sensors) {
    Serial.println("No valid sensors found");
    while (1)
      ;
  }
}

/*
*Function Name: setup_ObjectDetection
*Parameters: None
*Returns: void
*Description: Setup the ObjDetect Sensors by Shutdown Pins 
*  then using initialize function
*/

void setup_ObjectDetection(){
  for (int i = 0; i < COUNT_SENSORS; i++) {
    pinMode(sensors[i].shutdown_pin, OUTPUT);
    digitalWrite(sensors[i].shutdown_pin, LOW);

    if (sensors[i].interrupt_pin >= 0)
      pinMode(sensors[i].interrupt_pin, INPUT_PULLUP);
  }
  initialize_ObjDetectSensors();
}

/*
*Function Name: run_ObjectDetection
*Parameters: None
*Returns: void
*Description: Read to the amount of sensors and grabs values to save 
*       it in the packet struct
*/

void run_ObjectDetection(){
  // Read the data from the sensors using a 'for' loop:
  for (int i = 0; i < COUNT_SENSORS; i++) {
    objectDetectRanges_mm[i] = sensors[i].psensor->readRange();  // This is where the sensor's data is captured
    packet.objectDetectionSensors[i] = objectDetectRanges_mm[i];
  }
  
  // Print out the distances to the serial monitor, again using a 'for' loop:
  /*for (int i = 0; i < COUNT_SENSORS; i++) {
    Serial.print("Sensor #");
    Serial.print(i, DEC);
    Serial.print(" at IIC address 0x");
    Serial.print(sensors[i].id, HEX);
    Serial.print(": ");
    Serial.print(ranges_mm[i], DEC);
    Serial.print(" mm       ");
  }
  Serial.println();
  */

  // Delay until the next reading:
  //delay(200);  // Argument is in milliseconds
}

/*
*Function Name: setup_OLED
*Parameters: None
*Returns: Void
*Description: Initializes the OLED display
*/
void setup_OLED(){
  oled.init();             
  oled.clear();
}
