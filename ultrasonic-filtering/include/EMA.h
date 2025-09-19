
#ifndef EMA_H
#define EMA_H

#include <Arduino.h>

class EMA {

    private:

        float alpha;
        float filteredValue;
        float accum_error;

    public:

        EMA(float _alpha);
        float output(float _value);
        void reset();

};


#endif