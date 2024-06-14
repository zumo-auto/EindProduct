#include "MotorControl.h"

MotorControl::MotorControl() : lastError(0) {}

void MotorControl::setupMotors() {

    // Wacht tot knop A is ingedrukt en weer losgelaten.
    buttonA.waitForButton();
}

void MotorControl::controlMotors(int16_t speedDifference) {
    // Verkrijg individuele motorsnelheden. Het teken van speedDifference
    // bepaalt of de robot naar links of naar rechts draait.
    int16_t leftSpeed = (int16_t)maxSpeed + speedDifference;
    int16_t rightSpeed = (int16_t)maxSpeed - speedDifference;

    // Beperk onze motorsnelheden tot tussen 0 en maxSpeed.
    // Hierdoor draait hij niet om nadat hij wit of een andere kleur gemeten heeft.
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
