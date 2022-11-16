#include <NewPing.h>
#include <Arduino.h>
#include "BasicStepperDriver.h"

#define MOTOR_STEPS 200
#define RPM 20

#define MICROSTEPS 1

#define DIR1 4
#define STEP1 3

#define DIR2 6
#define STEP2 5

#define TRIG 8
#define ECHO 9
#define DIS 400

//#define MAX_ANGLE 1080

int trigPin = 8;    // TRIG pin
int echoPin = 9;    // ECHO pin

float duration_us, distance_cm;


BasicStepperDriver stepper1(MOTOR_STEPS, DIR1, STEP1);
BasicStepperDriver stepper2(MOTOR_STEPS, DIR2, STEP2);
NewPing sensor(TRIG, ECHO, DIS);

int d = 0;
int angle;
int pos = 0;

void setup() {       
//  stepper.begin(RPM, MICROSTEPS);
  Serial.begin(115200);
    // configure the trigger pin to output mode
  pinMode(TRIG, OUTPUT);
  // configure the echo pin to input mode
  pinMode(ECHO, INPUT);
  
}

void loop() {  

  ultraDis();
  
  
//  stepper.move(-MOTOR_STEPS*MICROSTEPS);

    
  

//  for (int i = 0; i < abs(comp); i++) {
//    stepper.rotate(i);
////    stepper2.rotate(i);
// 
//  }

}


void ultraDis(){
  d = sensor.ping_cm();
//  Serial.print(d);
//  Serial.println("cm");
  delay(1000);


  if (d <= 400 && d >300){
    distanceToRotation(1);    
    }
    
  if (d <= 300 && d >=200){
    distanceToRotation(2);   
    }

  if (d <= 200 && d >=100){
    distanceToRotation(3);    
    }
   
  if (d <= 100 && d >=0){
 
    
    distanceToRotation(4); 
    delay(1000);  
    }
  }



void distanceToRotation(int disdata){

    if (disdata ==1){
      stepper1.begin(5, MICROSTEPS);
      stepper2.begin(5, MICROSTEPS);
      for (int i = 0; i < 20; i++) {
        stepper1.rotate(i);
        stepper2.rotate(i);
        Serial.println(i);
      }

      for (int i = 0; i < 20; i++) {
        stepper1.rotate(-i);
        stepper2.rotate(-i);
      }
      
    
    }

    if (disdata ==2){

      stepper1.begin(10, MICROSTEPS);
      stepper2.begin(10, MICROSTEPS);
      for (int i = 0; i < 25; i++) {
        stepper1.rotate(i);
        stepper2.rotate(i);
        Serial.println(i);
      }

      for (int i = 0; i < 25; i++) {
        stepper1.rotate(-i);
        stepper2.rotate(-i);
      }
      
    
    
    }


    if (disdata ==3){
      stepper1.begin(30, MICROSTEPS);
      stepper2.begin(30, MICROSTEPS);
      for (int i = 0; i < 30; i++) {
        stepper1.rotate(i);
        stepper2.rotate(i);
        Serial.println(i);
      }

      for (int i = 0; i < 30; i++) {
        stepper1.rotate(-i);
        stepper2.rotate(-i);
      }
      

    
    }


    if (disdata ==4){
      stepper1.begin(50, MICROSTEPS);
      stepper2.begin(50, MICROSTEPS);
      for (int i = 0; i < 40; i++) {
        stepper1.rotate(i);
        stepper2.rotate(i);
        Serial.println(i);
      }

      for (int i = 0; i < 40; i++) {
        stepper1.rotate(-i);
        stepper2.rotate(-i);
      }
      
  

      delay(500); 
        
    }


 
  
  }
