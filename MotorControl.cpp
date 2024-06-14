#include "MotorControl.h"

MotorControl::MotorControl() : lastError(0) {}

void MotorControl::setupMotors() {
    // Uncomment if necessary to correct motor directions:
    //motors.flipLeftMotor(true);
    //motors.flipRightMotor(true);

    // Wait for button A to be pressed and released.
    buttonA.waitForButton();
}

void MotorControl::controlMotors(int16_t speedDifference) {
    // Get individual motor speeds. The sign of speedDifference
    // determines if the robot turns left or right.
    int16_t leftSpeed = (int16_t)maxSpeed + speedDifference;
    int16_t rightSpeed = (int16_t)maxSpeed - speedDifference;

    // Constrain our motor speeds to be between 0 and maxSpeed.
    // One motor will always be turning at maxSpeed, and the other
    // will be at maxSpeed-|speedDifference| if that is positive,
    // else it will be stationary. For some applications, you
    // might want to allow the motor speed to go negative so that
    // it can spin in reverse.
    leftSpeed = constrain(leftSpeed, 0, (int16_t)maxSpeed);
    rightSpeed = constrain(rightSpeed, 0, (int16_t)maxSpeed);

    motors.setSpeeds(leftSpeed, rightSpeed);
}

int16_t MotorControl::getLastError() const {
    return lastError;
}

void MotorControl::setLastError(int16_t error) {
    lastError = error;
}

Zumo32U4Motors& MotorControl::getMotors() {
    return motors;
}
