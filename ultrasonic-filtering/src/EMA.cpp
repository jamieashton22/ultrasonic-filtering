
#include "EMA.h"

EMA::EMA(float _alpha) {

    alpha = _alpha;
    filteredValue = 0;

}

float EMA::output(float _value){

    if (filteredValue == 0){
        filteredValue = _value;
    }
    else{
    filteredValue = (alpha * _value) + ((1 - alpha)*filteredValue);
    }

    return(filteredValue);

}