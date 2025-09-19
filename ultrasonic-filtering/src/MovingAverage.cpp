
#include "MovingAverage.h"

MovingAverage::MovingAverage(int _numReadings) {

    numReadings = _numReadings;
    reset();
    
}

void MovingAverage::reset() {

    for(int i= 0; i < MAX_SIZE; i++){
        readings[i] = 0;
    }

    index = 0;
    total = 0;
}

float MovingAverage::update(float _newValue){

    float average;
    total = total - readings[index];
    readings[index] = _newValue;
    total = total + readings[index];
    index++;

    if (index >= numReadings){
        index = 0;
    }

    average = total/numReadings;

    return average;
}
