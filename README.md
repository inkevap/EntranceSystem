# EntranceSystem - Sistema de Control de Acceso con Arduino

Sistema de control de acceso desarrollado para Arduino que permite gestionar el ingreso de personas mediante validación de códigos PIN, registro de accesos y apertura automática de puertas.

## 📋 Descripción

Este proyecto implementa un sistema completo de control de acceso que:

- **Valida códigos PIN** ingresados mediante un teclado matricial 4x4
- **Registra los accesos** en una tarjeta SD con fecha y hora (usando módulo RTC)
- **Controla dos puertas** mediante servomotores que se abren automáticamente cuando detecta proximidad
- **Muestra información** en una pantalla LCD 16x2 con interfaz I2C
- **Gestiona una base de datos** de usuarios con nombres, códigos y tipos de acceso

## 🔧 Componentes Requeridos

### Hardware
- Arduino (compatible con el entorno Wokwi)
- Teclado matricial 4x4 (Keypad)
- Pantalla LCD 16x2 con módulo I2C
- 2 Servomotores (para las puertas)
- Sensor ultrasónico HC-SR04 (detección de proximidad)
- Módulo RTC DS1307 (fecha y hora)
- Lector de tarjetas SD
- Tarjeta SD formateada en FAT16/FAT32

### Librerías
Las siguientes librerías son necesarias (ver `libraries.txt`):
- [Keypad](https://github.com/Chris--A/Keypad) - Control del teclado matricial
- [LiquidCrystal I2C](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) - Control de LCD
- [Servo](https://www.arduino.cc/reference/en/libraries/servo/) - Control de servomotores
- [SdFat](https://github.com/greiman/SdFat) - Control de tarjeta SD
- [RTClib](https://github.com/adafruit/RTClib) - Control del módulo RTC

## 📁 Estructura del Proyecto

```
EntranceSystem/
├── Main.ino              # Archivo principal del programa
├── Settings.h            # Configuración de pines y constantes
├── Database.cpp          # Base de datos de usuarios
├── Map.h                 # Estructura de datos para usuarios
├── Input.h               # Control del teclado y LCD
├── Doors.h               # Control de servomotores (puertas)
├── Ultrasonic.h          # Sensor de distancia ultrasónico
├── SDController.h        # Control de escritura/lectura en SD
├── RTCController.h       # Control de fecha y hora (RTC)
├── libraries.txt         # Lista de librerías requeridas
└── README.md             # Este archivo
```

## ⚙️ Configuración

### Pines Utilizados

| Componente | Pines |
|------------|-------|
| Servo 1 (Puerta 1) | Pin 7 |
| Servo 2 (Puerta 2) | Pin 6 |
| Sensor Ultrasónico - Trigger | Pin 9 |
| Sensor Ultrasónico - Echo | Pin 8 |
| Teclado - Filas | Pines 5, 4, 3, 2 |
| Teclado - Columnas | Pines A3, A2, A1, A0 |
| SD Card - CS | Pin 10 |

### Usuarios Predeterminados

El sistema incluye los siguientes usuarios configurados en `Database.cpp`:

| Nombre | Código PIN | Tipo |
|--------|-----------|------|
| Kevin | 1792 | Owner |
| Calvin | 1842 | Owner |
| Fred | 2971 | Visitor |
| Admin | 7777 | Admin |

> **Nota:** El código `7777` otorga acceso de administrador y permite leer el registro de accesos.

## 🚀 Funcionamiento

1. **Inicio**: El sistema muestra "Welcome" y "Input Code" en el LCD
2. **Ingreso de Código**: El usuario presiona cualquier tecla e ingresa su código PIN de 4 dígitos
3. **Validación**: 
   - Si el código es correcto: muestra nombre y tipo de usuario
   - Si el código es incorrecto: muestra "Wrong Code / No User Found"
4. **Detección de Proximidad**: El sensor ultrasónico espera a que el usuario se acerque (< 100 cm)
5. **Apertura de Puertas**: Los servos giran para abrir las puertas durante 2 segundos
6. **Cierre**: Las puertas se cierran automáticamente
7. **Registro**: El acceso se guarda en la tarjeta SD con fecha y hora

## 📝 Archivos Generados

- **Users.txt**: Contiene el registro de todos los accesos con nombre, tipo y fecha/hora
- **Log.txt**: Archivo de logs del sistema

## 🔧 Personalización

### Agregar Nuevos Usuarios

Edita el archivo `Database.cpp` y modifica el array `USERS`:

```cpp
const int Settings::USERS_LENGTH = 5; // Actualiza el conteo
const Map Settings::USERS[Settings::USERS_LENGTH] = {
    {"Kevin", 1792, "Owner"},
    {"Calvin", 1842, "Owner"},
    {"Fred", 2971, "Visitor"},
    {"Admin", 7777, "Admin"},
    {"NuevoUsuario", 1234, "Resident"} // Nuevo usuario
};
```

### Configurar Distancia de Detección

En `Settings.h`, modifica `CLOSE_ENOUGH_DISTANCE` (en centímetros):

```cpp
static const int CLOSE_ENOUGH_DISTANCE = 100; // Centímetros
```

## 🛠️ Uso en Wokwi

Este proyecto está diseñado para funcionar en el simulador [Wokwi](https://wokwi.com/):

1. Abre el proyecto en Wokwi
2. Asegúrate de que las librerías estén listadas en `libraries.txt`
3. Presiona "Play" para iniciar la simulación

## 📄 Licencia

Este proyecto incluye un archivo LICENSE. Consulta el archivo para más detalles.

## 👥 Autores

Proyecto desarrollado como sistema de control de acceso para Arduino.

---

**Nota**: Este proyecto fue diseñado originalmente para el simulador Wokwi. Para implementación en hardware real, verifica las conexiones y la compatibilidad de los componentes.
