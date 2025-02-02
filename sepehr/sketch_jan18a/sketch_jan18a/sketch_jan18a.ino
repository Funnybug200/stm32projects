#include <Stepper.h>                         // Include the Stepper motor header file 
#define STEPS 32                             // change this to the number of steps on your motor
const int speedm = PA4;                      // Pin for input speed
Stepper stepper(STEPS, PA0, PA2, PA1, PA3);  // create an instance of the stepper class using the steps and pins
int rotate = 0;                                 //declare variable rotate with 0 for input rotation.
void setup()                                 //Setup() runs only once
{
  Serial.begin(9600);                        //begins serial communication at 9600baud rate
  pinMode(speedm,INPUT);   
  pinMode(PB7,INPUT);                  //set pin PA4 as input
}
bool check=true;
bool dir=true;
void loop()                                   //loop() runs infinitely
{
  check=digitalRead(PB7);
  if (check)                   //Checks if serial data is entered or not in serial monitor
  {
    if(dir){rotate = 1024;}else{rotate = -1024;}                  //gets the value for rotation from serial monitor
    int adc = analogRead(speedm);             //read analog value from pin PA0
    int result = map(adc, 0, 4096, 0, 1023);  //maps the result of ADC from (0to4096)with (0to1023) 
    stepper.setSpeed(result);                 //sets the speed of motor
    stepper.step(rotate);                        //makes the motor to rotate
    Serial.println(rotate); 
    check=false;
    dir=!dir;                     //prints the value you specified to rotate
  }
}