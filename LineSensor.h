#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Zumo32U4.h>

class LineSensor {
public:
    LineSensor();
    void calibrateSensors(Zumo32U4Motors& motors);
    int16_t readLineSensor();

private:
    Zumo32U4LineSensors lineSensors;
    unsigned int lineSensorValues[5];
};

#endif // LINESENSOR_H
