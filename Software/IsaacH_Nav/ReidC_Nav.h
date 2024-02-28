#include <Ultrasonic.h> //CHANGE
#include <Adafruit_VL53L0X.h>  //CHANGE

//Line Following variables
const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];

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
  {&sensor3, &Wire, 0x32, 22, 23, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},
  /*
  // For 'sensor4', define the IIC accress as hexadecimal value 0x33. Assign digital pin #24 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #25 to the sensor's INTERRUPT pin.
  {&sensor4, &Wire, 0x33, 24, 25, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},
  
  // For 'sensor5', define the IIC accress as hexadecimal value 0x34. Assign digital pin #26 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #27 to the sensor's INTERRUPT pin.
  {&sensor5, &Wire, 0x34, 26, 27, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},

  // For 'sensor6', define the IIC accress as hexadecimal value 0x35. Assign digital pin #28 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #29 to the sensor's INTERRUPT pin.
  {&sensor6, &Wire, 0x35, 28, 29, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},

  // For 'sensor7', define the IIC accress as hexadecimal value 0x36. Assign digital pin #30 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #31 to the sensor's INTERRUPT pin.
  {&sensor7, &Wire, 0x36, 30, 31, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0},
  
  // For 'sensor8', define the IIC accress as hexadecimal value 0x37. Assign digital pin #32 to this 
  // sensor's XSHUT pin (shut-down pin). Assign digital pin #25 to the sensor's INTERRUPT pin.
  {&sensor8, &Wire, 0x37, 32, 33, Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT, 0, 0}
  */
};

//Object Detection Variables
const int COUNT_SENSORS = sizeof(sensors) / sizeof(sensors[0]); //CHANGE
uint16_t objectDetectRanges_mm[COUNT_SENSORS]; //CHANGE

void run_Location(); //CHANGE
void initialize_ObjDetectsensors(); //CHANGE
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
  delay(60);
}

/*
*Function Name: initialize_ObjDetectsensors
*Parameters: None
*Returns: void
*Description: Initialize the Object Detection Sensors
*/

void initialize_ObjDetectsensors(){
  bool found_any_sensors = false;
  // Set all shutdown pins low to shutdown sensors
  for (int i = 0; i < COUNT_SENSORS; i++){
    digitalWrite(sensors[i].shutdown_pin, LOW);
  }
  delay(10);

  for (int i = 0; i < COUNT_SENSORS; i++) {
    // one by one enable sensors and set their ID
    digitalWrite(sensors[i].shutdown_pin, HIGH);
    delay(10); // give time to wake up.
    if (sensors[i].psensor->begin(sensors[i].id, false, sensors[i].pwire,
                                  sensors[i].sensor_config)) {
      found_any_sensors = true;
    } else {
      Serial.print(i, DEC);
      Serial.print(F(": c to start\n"));
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
*  then using intialize function
*/

void setup_ObjectDetection(){
  Serial.println(F("VL53LOX_multi start, initialize IO pins"));
  for (int i = 0; i < COUNT_SENSORS; i++) {
    pinMode(sensors[i].shutdown_pin, OUTPUT);
    digitalWrite(sensors[i].shutdown_pin, LOW);

    if (sensors[i].interrupt_pin >= 0)
      pinMode(sensors[i].interrupt_pin, INPUT_PULLUP);
  }
  Serial.println(F("Starting..."));
  initialize_ObjDetectsensors();
}

/*
*Function Name: run_ObjectDetection
*Parameters: None
*Returns: void
*Description: 
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
  delay(200);  // Argument is in milliseconds
}