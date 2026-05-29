#pragma once
#include "Map.h"
#include <Arduino.h>

class Settings {
  public:
    /*------------------PINOUT CONFIGURATION---------------------------*/
    //Servos
    static const int SERVO1 = 7;
    static const int SERVO2 = 6;//12;
    //Ultrasonic Sensor
    static const int TRIGGER_PIN = 9;
    static const int ECHO_PIN = 8;


    /*--------------ADD MORE USERS IN DATABASE.CPP--------------------*/
    static const int USERS_LENGTH;
    static const Map USERS[];

    /*------------------ULTRASONIC DISTANCE---------------------------*/
    static const int CLOSE_ENOUGH_DISTANCE = 100; // Meters

    /*------------------PINOUT INITIALIZE---------------------------*/
    static init() {
      //Servo
      pinMode(SERVO1, OUTPUT);
      pinMode(SERVO2, OUTPUT);
      pinMode(TRIGGER_PIN, OUTPUT);
      pinMode(ECHO_PIN, INPUT);
    }
};