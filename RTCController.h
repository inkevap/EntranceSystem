#pragma once
#include "RTClib.h"

class RTCController {
  private:

    inline static RTC_DS1307 rtc;
    const char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  public:

    static void init() {
      if (! rtc.begin()) {
        // codigo de error si no inicia RTC
      }
    }

    static String getDate() {
      DateTime now = rtc.now();
      return " " + String(now.day()) + "/" + String(now.month()) +  "/" + String(now.year()) + " | " + String(now.hour()) + ":" + String(now.minute());
    }

};

