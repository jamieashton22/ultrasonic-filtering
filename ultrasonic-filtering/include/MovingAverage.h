
#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

#include <Arduino.h>

class MovingAverage {

    private: 

        static const int MAX_SIZE = 20;
        int numReadings;
        float readings[MAX_SIZE];
        int index = 0;
        float total = 0;

    public:

        MovingAverage(int _numreadings);
        float update(float _newValue);

        void reset();

};



#endif