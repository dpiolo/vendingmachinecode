#include <LiquidCrystal.h>
#include <Stepper.h>

//const int pinLaser = 4; // output signal pin of laser module/laser pointer
//const int pinReceiver = 3;
const int b1 = 9;
const int b2 =10;
 // input signal pin of receiver/detector (the used module does only return a digital state)

const int buttonPin[] = {9,10};
int Triggered = 0;
int Coin = 0;
const int stepsPerRevolution = 2038;

Stepper myStepper = Stepper(stepsPerRevolution, 3, 4, 5, 6);

LiquidCrystal lcd_2(1, 2, A0, A1, A2, A3);

void setup() {
  //pinMode(pinLaser, OUTPUT); // set the laser pin to output mode
  //pinMode(pinReceiver, INPUT);

  pinMode(b1, INPUT);
  pinMode(b2, INPUT); // set the laser pin to output mode
  //digitalWrite(pinLaser, HIGH); // emit red laser
  //Serial.begin(9600); // Setup serial connection for print out to console


  lcd_2.begin(16, 2); // Set up the number of columns and rows on the LCD.
  lcd_2.display();
  lcd_2.print("Insert Coin");
}

void loop() {

  //int value = digitalRead(pinReceiver); // receiver/detector send either LOW or HIGH (no analog values!)
  //Serial.println(value); // send value to console // wait for 1000ms


  if (Coin <= 0) {
    lcd_2.clear();
    lcd_2.print("Insert Coin");
    while (!(Coin > 0)) {
      delay(100); // Wait for 100 millisecond(s)
    }
  }

int CoinAdd = digitalRead(b1);
int Selection1 = digitalRead(b2);

   if (CoinAdd == LOW) {
      Coin += 1;
    lcd_2.clear();
    lcd_2.print("Coins: ");
    lcd_2.print(Coin);
    while (!(CoinAdd == LOW)) {
      delay(100);
      CoinAdd = digitalRead(b1); // Wait for 100 millisecond(s)
    }


   if (Selection1 == LOW) {
    myStepper.setSpeed(5);
      myStepper.step(stepsPerRevolution);
      delay(1000);
    }
   }
}