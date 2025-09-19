
#include "Ultrasound.h"

Ultrasound::Ultrasound(int trig, int echo) {

    trigPin = trig;
    echoPin = echo;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

}

float Ultrasound::getDistance() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    float duration = pulseIn(echoPin, HIGH);
    float distance = 0.5 * duration * 0.0343;
    return distance;
}