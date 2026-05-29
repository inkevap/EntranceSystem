#pragma once
#include "SdFat.h"
#include "Map.h"
#include "Settings.h"
#include "RTCController.h"

#define USER_DB  "Users.txt"
#define LOG "Log.txt"

#define SPI_SPEED SD_SCK_MHZ(4)
#define CS_PIN 10

class SDController {
  private:

    inline static SdFat sd;
    inline static File file;


  public:

    static void init() {
      Serial.begin(115200);
      if (!sd.begin(CS_PIN, SPI_SPEED)) {
        if (sd.card()->errorCode()) {
          Serial.println("SD initialization failed.");
        } else if (sd.vol()->fatType() == 0) {
          Serial.println("Can't find a valid FAT16/FAT32 partition.");
        } else {
          Serial.println("Can't determine error type");
        }
      }
    }

    static boolean logEntrance(Map user) {
      // Escribir sobre archivo
      file = sd.open(USER_DB, FILE_WRITE);
      if (file) {
        file.print(user.key);
        file.print(" ");
        file.print(user.type);
        file.println(RTCController::getDate());
        file.close(); // ¡Importante! Cierra para asegurar escritura
        return true;
        Serial.println("Archivo escrito correctamente.");
      } else {
        Serial.println("Error al crear/abrir el archivo.");
      }
    }

    static void readEntrance() {
      // Leer Archivo
      file = sd.open(USER_DB, FILE_READ);
      if (file) {
        Serial.println("Registros:");
        while (file.available()) {
          Serial.write(file.read());
        }
        file.close();
      } else {
        Serial.println("No se pudo abrir para lectura.");
      }
    }

};

