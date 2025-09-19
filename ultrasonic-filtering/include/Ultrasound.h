
#ifndef ULTRASOUND_H
#define ULTRASOUND_H

#include <Arduino.h>

class Ultrasound {
    private:
        int trigPin;
        int echoPin;

    public:

        Ultrasound(int trig, int echo);
        float getDistance();

};

#endif