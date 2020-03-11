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
  if(buttonState == HIGH){
    while(startButton == HIGH){}
    Serial.println("Start");
    Serial.println("Furo 1");
    digitalWrite(drill, HIGH);
    digitalWrite(secondPosition, LOW);
    digitalWrite(fling, LOW);
    delay(100);
    digitalWrite(drill, LOW);
    delay(900);
    Serial.println("Muda posição");
    delay(100);
    Serial.println("Furo 2");
    digitalWrite(drill, HIGH);
    delay(100);
    digitalWrite(drill, LOW);
    delay(900);
    Serial.println("Volta posição");
    digitalWrite(secondPosition, LOW);
    delay(100);
    Serial.println("Ejeta pino");
    digitalWrite(fling, HIGH);
    delay(100);
    digitalWrite(fling, LOW);
    delay(500);
    Serial.println("Finish");
  }

}
