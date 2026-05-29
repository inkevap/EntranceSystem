#include "Settings.h"

  /*------------------USER'S DATABASE---------------------------*/
const int Settings::USERS_LENGTH = 4; //update both the list and the count
const Map Settings::USERS[Settings::USERS_LENGTH] = {
    {"Kevin", 1792, "Owner"},
    {"Calvin", 1842, "Owner"},
    {"Fred", 2971, "Visitor"},
    {"Admin", 7777, "Admin"}
};