#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>

int n=1;
unsigned long time;
File TempFile;
File ExcelTemp;
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
const int chipSelect = 8;
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();

  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);

  // The chipSelect pin you use should also be set to output
  pinMode(chipSelect, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop(void)
{
  time = millis();

String a = Serial.readString();
if (a=="end"){
  Serial.println(a);
  Serial.end();
  TempFile.close();
    int n=1;
  while(1){};//Never ending loop.... it will not leave/ "Stopping"
}
else{
  while (n<2){
    TempFile = SD.open("TEMP_LOG.txt", FILE_WRITE);
if (SD.exists("TEMP_LOG.txt")) {
  } else {
    Serial.println("TEMO_LOG.txt doesn't exist.");
  }
  // if the file is available, write to it:
  if (TempFile) {
    TempFile.println("NEW RUN");
      TempFile.close();
  }
  /*  sensors.requestTemperatures(); // Send the command to get temperatures
    Serial.print("TEMPERATURE: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? 
  Serial.print(" C");

  Serial.print("\t TIME: ");
  Serial.print(time/1000);
  Serial.println(" Seconds");

  String dataString = "";
    dataString += String(sensors.getTempCByIndex(0));
    
TempFile = SD.open("TEMP_LOG.txt", FILE_WRITE);
if (SD.exists("TEMP_LOG.txt")) {
  } else {
    Serial.println("TEMO_LOG.txt doesn't exist.");
  }
  // if the file is available, write to it:
  if (TempFile) {
    TempFile.println("TEMPERATURE: "+dataString+"\t"+"TIME: "+time/1000+" Seconds");
    TempFile.close();
    // print to the serial port too:
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening TEMP_LOG.txt");
  }*/
  n++;
  }
 
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //Serial.print(" Requesting temperature...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");

  Serial.print("TEMPERATURE: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? 
  Serial.print(" C");

  Serial.print("\t TIME: ");
  Serial.print(time/1000);
  Serial.println(" Seconds");
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire

   String dataString = "";
    dataString += String(sensors.getTempCByIndex(0));
    
TempFile = SD.open("TEMP_LOG.txt", FILE_WRITE);
if (SD.exists("TEMP_LOG.txt")) {
  } else {
    Serial.println("TEMO_LOG.txt doesn't exist.");
  }
  // if the file is available, write to it:
  if (TempFile) {
    //TempFile.println("TEMPERATURE\t"+dataString+"\t"+"TIME\t"+time/1000+"\tSeconds");
    TempFile.println(dataString+"\t"+time/1000);
    TempFile.close();
    // print to the serial port too:
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening TEMP_LOG.txt");
  }
delay(500);
}
}
