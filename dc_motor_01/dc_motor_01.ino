// Motor 1 Pins
const int MOTOR1_PWM = 3;
const int IN_1 = 4;
const int IN_2 = 5;
// Motor 2 Pins
const int MOTOR2_PWM = 6;
const int IN_3 = 7;
const int IN_4 = 8;
// Potentiometer
const int POT = A0;
// Buttons pins
const int BUTTON_1 = 10;
const int BUTTON_2 = 11;
const int BUTTON_3 = 12;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int potValue = 0;
int currentState = 0;

void setup() {
  // Setup motor pins
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(MOTOR1_PWM, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(MOTOR2_PWM, OUTPUT);
  // Button pins
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);
  // Initialise serial
  Serial.begin(9600);
}

void loop() {
  buttonState1 = digitalRead(BUTTON_1);
  buttonState2 = digitalRead(BUTTON_2);
  buttonState3 = digitalRead(BUTTON_3);
  motorDemo();
  
  /* use the code below if you want to use a potentiometer
  insted of 3 momentary switches */
  //potValue = map(analogRead(POT), 0, 1024, 0, 255);
  //motorDemo(potValue); 
}

void motorDemo(){
  // Turn on motor
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  // Check which button has been pressed
  if(buttonState1 == HIGH){
    currentState = 0;
  }
  else if(buttonState2 == HIGH){
    currentState = 1;
  }
  else if(buttonState3 == HIGH){
    currentState = 2;
  }
  // Set speed according to which button has been pressed
  switch(currentState){
    case 0:
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      Serial.println("Turned off");
      break;
    case 1:
      // Set direction
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(MOTOR1_PWM, 127);
      analogWrite(MOTOR2_PWM, 127);
      Serial.println("Medium Speed");
      break;
    case 2:
      // Set direction
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(MOTOR1_PWM, 255);
      analogWrite(MOTOR2_PWM, 255);
      Serial.println("High Speed");
      break;
  }
  
  /* OLD CODE
  // Set speed
  if(speed != 0){
  analogWrite(MOTOR1_PWM, speed);
  }
  // Wait
  delay(1000);
  // Change direction
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  // Wait
  delay(1000);
  // Turn off motor
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  */
}

