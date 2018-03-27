/*
 * Code created for Baja Group 2 - Design Studio MCG 4149
 * Date: March 21 2018
 * Members: Conor Turner & Kyle Macmillan
 * 
 */

////////////////////////////////////////////////////////////////////////////////
 
/*
 * When using bluetooth, set port to COMM 4, open serial monitor, 
 * wait for HC-06 lights to turn solid and press reset on Arduino to begin code.
 */


#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>

#define ONE_WIRE_BUS 2 //Temperature sensor wired to pin 2
File myFile;

int counter =0; //Number of times temperature was read. Used with RunTime
int tempVal; //Temporary variable to track switch previous state
boolean printCounter = true; //Used to print a statement only on first loop of temp logging
double RunTime; //Simulated clock
String printString; //String that is being printed to serial monitor and txt file

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
sensors.begin(); //Open communication with temperature sensor

//Below are statements to simulate a switch using only a wire
pinMode(3,OUTPUT);
pinMode(5,INPUT);
digitalWrite(3,HIGH);
digitalWrite(5,LOW);
tempVal=0;
//End of switch simulation

  Serial.println();
  Serial.println("Dallas Temperature IC Control Library");
  Serial.println("OneWire Library");
  Serial.print("Initializing SD card...");

//Check to see if SD Card is wired properly
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // Create txt file to write to and open it
  // If file already exists, open it and code will append
  myFile = SD.open("TEMP_LOG.txt", FILE_WRITE);

  // If the file opened, write to it:
  if (myFile) {
    //Write to serial monitor
    Serial.println("NEW RUN");
    //Write to txt file
    myFile.println("NEW RUN");
    // close the file:
    myFile.close();
    //Print to serial monitor
    Serial.println("File Closed");
    Serial.println("Waiting for Hardware Connection...");
  } else {
    // If the file didn't open, print an error to serial monitor
    Serial.println("Error Opening TEMP_LOG.txt");
  }
}
void loop() {
  
  if (digitalRead(5)==LOW && tempVal==0)
  {
  //Wire from pin 3 is not plugged into pin 5 - simulating the switch is off
  //If switch is off, don't start logging temperature. 
  //Do nothing here until switch is turned on (wire from pin 3 plugged into pin 5)
  }

  else if (digitalRead(5)==HIGH) 
   {
    //Print one line to serial monitor to confirm that data logging has started
    //Only want this statement to be printed in the first loop of logging
    if (printCounter==true){
      Serial.println("Hardware Connection Made!");
      Serial.println("Temperature Logging Started");
    }
    //Statement printed once, now don't print again unless Arduino is reset
    printCounter=false; 
    
   //Creating simulated clock by multiplying delay time with counter (loop number)
   //This shows only the time that the temperature sensor is tracking and displaying temperature data
   RunTime = 500*counter;
   //Pin 3 is now plugged into pin 5, set switch temp state to true
   tempVal=1;
   //Request temperature value from temperature sensor 
   sensors.requestTemperatures();
   
   //Serial.println(tempVal);                     USED FOR TESTING
   
   //Open the txt file and be ready to write
   myFile = SD.open("TEMP_LOG.txt", FILE_WRITE);
   
   //myFile.println("File Open");                 USED FOR TESTING
   //Serial.println("File Open");                 USED FOR TESTING
   //myFile.println("Test "+String(counter));     USED FOR TESTING
   //Serial.println("Test"+String(counter));      USED FOR TESTING

   //Create string of temperature reading and time seperated by a tab
   printString=(String(sensors.getTempCByIndex(0))+"\t"+RunTime/1000);
   //Print the combined string to serial monitor
   Serial.println(printString);
   //Print the combined string to txt file
   myFile.println(printString);

   //Serial.print(sensors.getTempCByIndex(0));    USED FOR TESTING
   //Serial.print(time/1000);                     USED FOR TESTING
   //myFile.print(sensors.getTempCByIndex(0));    USED FOR TESTING
   //Serial.print(time/1000);                     USED FOR TESTING
   //myFile.println("File Closed");               USED FOR TESTING
   //Serial.println("File Closed");               USED FOR TESTING

   //Close the txt file
   myFile.close();
   //Increase counter
   counter++;
  }

  //If the switch was on and is now off, close the file and stay in this loop forever until arduino is reset
  else if (digitalRead(5)==LOW && tempVal==1) 
  {
    //Print to serial monitor
    Serial.println("Disconnected");
    Serial.println("File Closed");
    myFile.close();
    while(1){};
  }
  
  delay(500);
}


