/*

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  // set the data rate for the SoftwareSerial port
  mySerial.begin(38400);

}

void loop() { // run over and over
 if (mySerial.available()) {
    char data = mySerial.read();
    Serial.print(data);  
  }

  if (Serial.available()) {
    char data = Serial.read();
    mySerial.write(data); 
  }
}
