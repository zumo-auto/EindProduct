#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Zumo32U4.h>

class MotorControl {
public:
    MotorControl(); // Constructor
    void setupMotors();
    void controlMotors(int16_t speedDifference);
    int16_t getLastError() const;
    void setLastError(int16_t error);
    Zumo32U4Motors& getMotors(); // Getter for motors

private:
    Zumo32U4Motors motors;
    Zumo32U4ButtonA buttonA;
    int16_t lastError;
    static const uint16_t maxSpeed = 320;
};

#endif // MOTORCONTROL_H
