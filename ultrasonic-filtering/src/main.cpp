
#include <Arduino.h>
#include "Ultrasound.h"
#include "MovingAverage.h"
#include "EMA.h"
#include "Median.h"

#define ECHO 6
#define TRIG 5

#define MA_SIZE 10
#define EMA_ALPHA 0.5

#define WINDOW_SIZE 5;

Ultrasound sensor(TRIG, ECHO);
MovingAverage MovingAverageFilter(MA_SIZE);
EMA EMAFilter(0.5);
Median MedianFilter;

void setup() {

  Serial.begin(9600);

  // // MOVING AVERAGE 
  // filter.reset();

}

void loop() {

  float distance = sensor.getDistance();

  // // MOVING AVERAGE
  // float avgDistance = MovingAverageFilter.update(distance);

  // // EMA
  // float avgDistance = EMAFilter.output(distance);
  
  // MEDIAN FILTER
  float avgDistance = MedianFilter.update(distance);

  Serial.print(distance);
  Serial.print(",");
  Serial.println(avgDistance);
  delay(10);

 
}
