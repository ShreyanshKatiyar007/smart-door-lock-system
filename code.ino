#include <Servo.h>
#include <Keypad.h>

Servo ServoMotor;
char* password = "888";
int position = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = { 8, 7, 6, 9 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad = Keypad( makeKeymap (Keys), rowPins, colPins, ROWS, COLS );
int RedpinLock = 12;
int GreeninUnlock = 13;

void setup()
{
  ServoMotor.attach(11);
  LockedPosition(true);
}

void loop()
{
  char key = keypad.getKey();
  if (key == '*' || key == '#')
  {
    position = 0;
    LockedPosition(true);
  }
  if (key == password[position])
  {
    position ++;
  }
  if (position == 3)
  {
    LockedPosition(false);
  }
}
