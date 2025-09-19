
#include "Median.h"

Median::Median(){

    windowSize = WINDOW_SIZE;
    reset();
}

void Median::reset() {

    for(int i = 0; i < windowSize; i++){

        readings[i] = 0;

    }

    index = 0;
    
}

float Median::update(float newValue){

    float temp[windowSize];
    readings[index] = newValue;

    index++;
    
    if(index >= windowSize){
        index = 0;
    }


    // copy to a temporary buffer, sort that and return the median from that

    for(int i = 0; i< windowSize; i++){
        temp[i] = readings[i];
    }

    // sort
    insertionSort(temp, windowSize);

    // find and return the median

    return temp[WINDOW_SIZE_MIDDLE]; // REPLACE WITH uhhhhhh FINDING ACTUAL MEDIAN YKNOW

} 



// Function to sort an array
// using insertion sort
void Median::insertionSort(float arr[], int n)
{
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}