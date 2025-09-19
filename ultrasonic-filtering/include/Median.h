
#ifndef MEDIAN_H
#define MEDIAN_H
#define WINDOW_SIZE 9
#define WINDOW_SIZE_MIDDLE 4

class Median {

    private: 

        int windowSize;
        int index;
        float readings[WINDOW_SIZE];

    public:

        Median();
        float update(float newValue);
        void reset();
        void insertionSort(float arr[], int n);

};


#endif