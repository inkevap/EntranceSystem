#pragma once
#include "Settings.h"
#include <Arduino.h>

class Ultrasonic {
  private:

    long duration;
    float distance;
    float getDistance() {
      digitalWrite(Settings::TRIGGER_PIN, LOW);
      delayMicroseconds(2);
      digitalWrite(Settings::TRIGGER_PIN, HIGH);
      delayMicroseconds(10);
      digitalWrite(Settings::TRIGGER_PIN, LOW);
      duration = pulseIn(Settings::ECHO_PIN, HIGH);
      distance = duration * 0.0343 / 2; // speed of sounds divided by the 2 because it comes and goes
      return distance;
    }

  public:
    boolean isCloseEnough() {
      if (getDistance() < Settings::CLOSE_ENOUGH_DISTANCE) {
        return true;
      }
      return false;
    }

};