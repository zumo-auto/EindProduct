#include "LineSensor.h"

LineSensor::LineSensor() {
    lineSensors.initFiveSensors();
}

void LineSensor::calibrateSensors(Zumo32U4Motors& motors) {
    // Wait 1 second and then begin automatic sensor calibration
    // by rotating in place to sweep the sensors over the line
    delay(1000);
    for(uint16_t i = 0; i < 120; i++) {
        if (i > 30 && i <= 90) {
            motors.setSpeeds(-200, 200);
        } else {
            motors.setSpeeds(200, -200);
        }
        lineSensors.calibrate();
    }
    motors.setSpeeds(0, 0);
}

int16_t LineSensor::readLineSensor() {
    // Get the position of the line. Note that we *must* provide
    // the "lineSensorValues" argument to readLine() here, even
    // though we are not interested in the individual sensor readings.
    return lineSensors.readLine(lineSensorValues);
}
