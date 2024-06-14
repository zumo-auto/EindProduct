#include "LineSensor.h"
#include "MotorControl.h"

// Create instances of the LineSensor and MotorControl classes
LineSensor lineSensor;
MotorControl motorControl;

void setup() {
    motorControl.setupMotors();
    lineSensor.calibrateSensors(motorControl.getMotors());
}

void loop() {
    int16_t position = lineSensor.readLineSensor();

    // Our "error" is how far we are away from the center of the
    // line, which corresponds to position 2000.
    int16_t error = position - 2000;

    // Get motor speed difference using proportional and derivative
    // PID terms (the integral term is generally not very useful
    // for line following). Here we are using a proportional
    // constant of 1/4 and a derivative constant of 6, which should
    // work decently for many Zumo motor choices. You probably
    // want to use trial and error to tune these constants for your
    // particular Zumo and line course.
    int16_t speedDifference = error / 0.75 + 20 * (error - motorControl.getLastError());

    motorControl.setLastError(error);

    motorControl.controlMotors(speedDifference);
}
