#include <Arduino.h>
#include "BasicStepperDriver.h"

#define MOTOR_STEPS 200
#define RPM 120

// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
#define MICROSTEPS 1

// All the wires needed for full functionality
#define DIR 15
#define STEP 2

const int enable_moteur = 0;


BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);


void setup() {
    stepper.begin(RPM, MICROSTEPS);
    pinMode(enable_moteur,OUTPUT);
    digitalWrite(enable_moteur,HIGH);
}

void loop() { 
    stepper.rotate(200);
    stepper.move(-MOTOR_STEPS*MICROSTEPS);
    delay(5000);
}
