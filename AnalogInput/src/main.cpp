// I Petar Kirkov, 000800914 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else.

#include <Arduino.h> 

// Calculates physical units from a digitized value
float calculatePhysicalValue(float x, float fromLow, float fromHigh, float toLow, float toHigh)
{
  return (x - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}



void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
void loop() { 
  int iVal; 
  float temp;
  String judgement;

  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 

  // print value to the USB port 
  Serial.println("Digitized Value = " + String(iVal) + " is equivalent to an Analog Voltage = " + String(calculatePhysicalValue(iVal, 0, 1023, 0, 3.3)) + "V");
  

  // call function to calculate temperature reading
  temp = calculatePhysicalValue(iVal, 0, 1023, 0, 50);

  // if statement that changes judgement based on temperature reading
  if (temp < 10)
    judgement = "Cold!";
  else if (temp >= 10 && temp <= 15)
    judgement = "Cool";
  else if (temp >= 15 && temp <= 25)
    judgement = "Perfect";
  else if (temp >= 25 && temp <= 30)
    judgement = "Warm";
  else if (temp >= 30 && temp <= 35)
    judgement = "Hot";
  else
    judgement = "Too Hot!";
  
  // print temperature value to the USB port
  Serial.println("Digitized Value = " + String(iVal) + " is equivalent to a temperature input of " + String(temp) + " deg. C, which is " + judgement);

  // wait 2 seconds (2000 ms)
  delay(2000);

} 