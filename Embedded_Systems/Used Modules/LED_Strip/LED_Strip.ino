#define RED_LED 12
#define BLUE_LED 13
#define GREEN_LED 15

int gBright = 0;
int rBright = 0;
int bBright = 0;


void Set_Led(int gBright,int rBright,int bBright)
{
  analogWrite(RED_LED, rBright);
  analogWrite(BLUE_LED, bBright);
  analogWrite(GREEN_LED, gBright);
}


void setup() {
   pinMode(GREEN_LED, OUTPUT);
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);
}

void loop() {
  Set_Led(255, 255, 255);
  delay(2000);
  Set_Led(255, 0, 0);
  delay(2000);
  Set_Led(0, 255, 0);
  delay(2000);
  Set_Led(0, 0, 255);
  delay(2000);
  Set_Led(0, 0, 0);
  delay(2000);
}
