#define aref_voltage 5.0

//TMP36 Pin Variables
int sensorPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
 
void setup()
{
  Serial.begin(9600); 
  analogReference(EXTERNAL);
}


void loop()                   
{
 int reading = analogRead(sensorPin);  
 float voltage = reading * aref_voltage;
 voltage /= 1024.0; 
 
 // print out the voltage
 //Serial.print(reading); Serial.println(" read from analog");
 //Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree with 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC); // Serial.println(" degrees C"); 
 
 delay(1000);                                     //waiting a second
}
