#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

class Input {
  private:
    /*------------------KEYPAD PINOUT------------------*/
    //const byte KEYPAD_ROWS = 4; Can't reference this variables
    //const byte KEYPAD_COLS = 4; because they don't exist during the compilation stage 
    byte rowPins[4] = {5, 4, 3, 2}; // Row Pins
    byte colPins[4] = {A3, A2, A1, A0}; // Col Pins
    char keys[4][4] = {
      {'1', '2', '3', 'A'},
      {'4', '5', '6', 'B'},
      {'7', '8', '9', 'C'},
      {'*', '0', '#', 'D'}
    };

    Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);
    LiquidCrystal_I2C* lcd;
    char key;
  public:

    Input() : lcd(nullptr) //assign null even before the pointer is declared.
    /*Why? Because apparently it's a good practice if we use ref or pointers
    do i have idea of what i am doing? perhaps*/   
    {}

    /*init(LiquidCrystal_I2C& lcdRef){ //pariending para poder usar la referencia pta vida
      : lcd(lcdRef) //esto funciona por gloria de nuestro señor Jesucristo
    }// -----------Mentira no sirvió---------------*/

    init(LiquidCrystal_I2C& lcdRef){ // We create a ref of the lcd
      lcd = &lcdRef; // Save the lcd address to access to its methods later on
    }

    int getCode() {
      lcd->setCursor(5, 1);
      lcd->print("[____]");
      lcd->setCursor(6, 1);
      String code = "";
      while (code.length() < 4) {
        if (key >= '0' && key <= '9') {
          lcd->print('*');
          code += key;
        }
        key = keypad.getKey();
      }
      return code.toInt();
    }

    boolean hasBeenPressed(){
      key = keypad.getKey();
      if(key){
        return true;
      } return false;
    }

};

/*For future reference or modifications read documentation of Keypad here:
https://github.com/Chris--A/Keypad/blob/master/keywords.txt
*/
