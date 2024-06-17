#include "LineSensor.h"
#include "MotorControl.h"

// Maak instanties van de LineSensor- en MotorControl-klassen
LineSensor lineSensor;
MotorControl motorControl;

void setup() {
    motorControl.setupMotors();
    lineSensor.calibrateSensors(motorControl.getMotors());
}

void loop() {
    int16_t position = lineSensor.readLineSensor();

    // Onze "error" is hoe ver we van het midden van de lijn verwijderd zijn,
    // wat overeenkomt met positie 2000.
    int16_t error = position - 2000;

    // Hier sturen wij de motoren met behulp van proportionele en afgeleide
    // PID-termen (de integrale term is over het algemeen niet erg nuttig
    // voor lijnvolging).
    int16_t speedDifference = error / 0.75 + 20 * (error - motorControl.getLastError());

    motorControl.setLastError(error);

    motorControl.controlMotors(speedDifference);
}
