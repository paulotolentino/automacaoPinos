const int startButton = 13;
const int microSwitchTop = 12;
const int microSwitchBottom = 11;
const int drill = 3;
const int secondPosition = 4;
const int fling = 5;

const int drillDelay = 500;
const int repositionDelay = 200;
const int flingingDelay = 200;

int buttonState = 0;
int switchTop = 0;
int switchBottom = 0;
int state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(startButton, INPUT);
  pinMode(microSwitchTop, INPUT);
  pinMode(microSwitchBottom, INPUT);
  pinMode(drill, OUTPUT);
  pinMode(secondPosition, OUTPUT);
  pinMode(fling, OUTPUT);
  
  
  Serial.println("POSIÇÃO ORIGINAL...");
  digitalWrite(secondPosition, LOW);
  digitalWrite(fling, LOW);
  digitalWrite(drill, LOW);
  state = 0;  
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(startButton);
  switchTop = digitalRead(microSwitchTop);
  switchBottom = digitalRead(microSwitchBottom);

  Serial.println(switchBottom);

  if(buttonState == HIGH && switchTop == HIGH && switchBottom == LOW && state == 0){
    Serial.println("FURANDO...");
    digitalWrite(drill, HIGH);
    delay(drillDelay);
    digitalWrite(drill, LOW);
    digitalWrite(secondPosition, LOW);
    digitalWrite(fling, LOW);
    while(buttonState == HIGH) { 
      buttonState = digitalRead(startButton);
      switchTop = digitalRead(microSwitchTop);
      switchBottom = digitalRead(microSwitchBottom);
    }
    while(switchTop == HIGH) { 
      buttonState = digitalRead(startButton);
      switchTop = digitalRead(microSwitchTop);
      switchBottom = digitalRead(microSwitchBottom);
    }
  }else if(buttonState == LOW && switchTop == HIGH && switchBottom == LOW && state == 1){
    Serial.println("SEGUNDA POSIÇÃO...");
    digitalWrite(secondPosition, HIGH);
    delay(repositionDelay);
    Serial.println("FURANDO...");
    digitalWrite(drill, HIGH);
    delay(drillDelay);
    digitalWrite(drill, LOW);
    digitalWrite(secondPosition, LOW);
    digitalWrite(fling, LOW);
    while(switchTop == HIGH) { 
      buttonState = digitalRead(startButton);
      switchTop = digitalRead(microSwitchTop);
      switchBottom = digitalRead(microSwitchBottom);
    }
  }else if(buttonState == LOW && switchTop == HIGH && switchBottom == LOW && state == 2){
    Serial.println("EJETANDO...");
    digitalWrite(fling, HIGH);
    delay(flingingDelay);
    Serial.println("POSIÇÃO ORIGINAL...");
    digitalWrite(secondPosition, LOW);
    digitalWrite(fling, LOW);
    digitalWrite(drill, LOW);
  }else if(switchBottom == HIGH){
    state++;
    if(state == 3) state = 0;
    while(switchBottom == HIGH) { 
      buttonState = digitalRead(startButton);
      switchTop = digitalRead(microSwitchTop);
      switchBottom = digitalRead(microSwitchBottom);
    }
  }
}
