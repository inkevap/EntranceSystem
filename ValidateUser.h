#pragma once
#include "Map.h"
#include "SDController.h"

class ValidateUser {
  private:
    Map currentUser = {"", -1, ""};

  public:

    boolean validateCode(int code) {
      if (code == 7777) {
        SDController::readEntrance();
        currentUser = {"Admin", 7777, "Admin"};
      } else {
        for (int i = 0; i < Settings::USERS_LENGTH; i++) {
          if (Settings::USERS[i].value == code) {
            currentUser = Settings::USERS[i];
            SDController::logEntrance(Settings::USERS[i]);
            return true;
          }
        }
        return false;
      }
    }

    String getName() {
      if (currentUser.value != -1) {
        return currentUser.key;
      }
      return "Not Found";
    }

    String getType() {
      if (currentUser.value != -1) {
        return currentUser.type;
      }
      return "Not Found";
    }

    boolean removeUser() {
      currentUser = {"", -1, ""};
      return true;
    }

};