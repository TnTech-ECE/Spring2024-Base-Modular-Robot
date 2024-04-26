#include <SD.h>
 
int analogPin = A2; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read
unsigned long int num_cycles = 0;

File myFile, myFile2;
 
void setup()
{
  Serial.begin(9600);
  // Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(53, OUTPUT);

  pinMode(5, OUTPUT); // toggle power board pin
  pinMode(13, OUTPUT);
 
  if (!SD.begin(53)) {
    Serial.println("initialization failed!");
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    return;
  }
  // Serial.println("initialization done.");
 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  // myFile = SD.open("test.txt", FILE_WRITE);
 
  // // if the file opened okay, write to it:
  // if (myFile) {
  //   Serial.print("Writing to test.txt...");
  //   myFile.println("testing 1, 2, 3.");
	// // close the file:
  //   myFile.close();
  //   Serial.println("done.");
  // } else {
  //   // if the file didn't open, print an error:
  //   Serial.println("error opening test.txt");
  // }
}
 
void loop()
{
  num_cycles++;
  // OFF
  digitalWrite(5, HIGH); // sets the digital pin 13 on
  delay(50);
  // val = analogRead(analogPin);  // read the input pin
  // Serial.println(val);          // debug value

  // ON
  digitalWrite(5, LOW);  // sets the digital pin 13 off
  delay(50);            // waits for a second

  val = analogRead(analogPin);  // read the input pin
  // Serial.println(val);          // debug value

  // if (val == 1023) {
  //   Serial.print("Num Cycles: ");
  //   Serial.println(num_cycles);
  //   while (1) {}
  // }
  myFile = SD.open("finalcycle.txt", FILE_WRITE);
  myFile.print(num_cycles);
  myFile.close();

  if ((val < 818) && (num_cycles > 100)) { // less than about 4 V

    myFile = SD.open("final.txt", FILE_WRITE);
    if (myFile) {
      myFile.println(num_cycles);
      myFile.close();
    }
    // myFile.print(num_cycles);
    // myFile.close();

    myFile = SD.open("cycles.csv", FILE_WRITE);
    myFile.print(num_cycles);
    myFile.print(",");
    myFile.print(val);
    myFile.print(",");
    myFile.println("<-----FAILED");
    myFile.close();

    while (1) {}
  }
  myFile = SD.open("cycles.csv", FILE_WRITE);
  myFile.print(num_cycles);
  myFile.print(",");
  myFile.println(val);
  myFile.close();
}