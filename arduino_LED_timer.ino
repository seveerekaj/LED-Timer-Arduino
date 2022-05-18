const int LED1 = 3;
const int LED2 = 5;
const int LED3 = 7;
const int LED4 = 9;
const int BUTTON1 = 10;
const int BUTTON2 = 12;
const unsigned long TIMER_SET_TIME = 432000000; // 5 days

int buttonState = 0;
unsigned long button1PressTime = 0;
unsigned long button2PressTime = 0;
unsigned long currentTime = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
}

void loop() {
  queryTimer(button1PressTime, setLedGroup1);
  queryTimer(button2PressTime, setLedGroup2);
  queryButton(BUTTON1, button1PressTime);
  queryButton(BUTTON2, button2PressTime);
}

void queryButton(int button, unsigned long &buttonPressTime) {
  buttonState = digitalRead(button);
  if(buttonState == LOW) {
    buttonPressTime = millis();
  }
}

void queryTimer(unsigned long buttonPressTime, void (*setLedGroup)(int)) {
  currentTime = millis();
  if(!buttonPressTime || currentTime - buttonPressTime > TIMER_SET_TIME) {
    setLedGroup(HIGH);
  } else {
    setLedGroup(LOW);
  }
}

void setLedGroup1(int setting) {
  digitalWrite(LED1, setting);
  digitalWrite(LED2, setting);
}

void setLedGroup2(int setting) {
  digitalWrite(LED3, setting);
  digitalWrite(LED4, setting);
}