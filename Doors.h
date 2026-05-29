#pragma once
#include <Servo.h>
#include "Settings.h"

class Doors {
  private:
    Servo door1;
    Servo door2;
    int pinDoor1;
    int pinDoor2;
  public:


    Doors() {
      this->pinDoor1 = Settings::SERVO1;
      this->pinDoor2 = Settings::SERVO2;
    }

    void init() {
      door1.attach(pinDoor1);
      door2.attach(pinDoor2);
      door1.write(180);
      door2.write(0);
    }

    void open() {
      door1.write(0);
      door2.write(180);
      delay(2000);
    }

    void close() {
      door1.write(180);
      door2.write(0);
      delay(2000);
    }
};