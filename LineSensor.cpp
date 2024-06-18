#include "LineSensor.h"

LineSensor::LineSensor() {
    lineSensors.initFiveSensors();
}

void LineSensor::calibrateSensors(Zumo32U4Motors& motors) {
    // Wacht 1 seconde en begin dan met automatische sensorcalibratie
    // door op de plaats te draaien om de sensoren over de lijn te bewegen
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
    // Verkrijg de positie van de lijn. Merk op dat we *moeten* 
    // "lineSensorValues" argument aan readLine() hier geven, zelfs
    // als we niet geïnteresseerd zijn in de individuele sensorwaarden.
    return lineSensors.readLine(lineSensorValues);
}
