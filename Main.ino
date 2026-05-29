//Libraries
#include <LiquidCrystal_I2C.h>
#include "Input.h"
#include "Doors.h"
#include "ValidateUser.h"
#include "Ultrasonic.h"
#include "SDController.h"
#include "RTCController.h"

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Instances
Doors entrance;
ValidateUser validateUser;
Ultrasonic distance;
Input input;


void setup() {

  Settings::init();
  entrance.init();
  lcd.init();
  input.init(lcd);
  SDController::init();
  RTCController::init();
}

void loop() {

  lcd.setCursor(4, 0);
  lcd.print("Welcome");
  lcd.setCursor(3, 1);
  lcd.print("Input Code");

  if (input.hasBeenPressed()) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Code:");
    int code = input.getCode(); // if they ask you about this code, feign being dead kev
    if (validateUser.validateCode(code)) {
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print(validateUser.getName());
      lcd.setCursor(5, 1);
      lcd.print(validateUser.getType());
      while (!distance.isCloseEnough()) {} //Wait til they're close enough
      entrance.open();
      delay(2000);
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Closing Door");
      delay(2000);
      entrance.close();
      lcd.clear();
      validateUser.removeUser();

    } else {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Wrong Code");
      lcd.setCursor(1, 1);
      lcd.print("No User Found");
      delay(5000);
      lcd.clear();
    }
  }


}


