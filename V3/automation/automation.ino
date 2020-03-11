const int startButton = 2;
const int drill = 13;
const int secondPosition = 12;
const int fling = 5;
const int beep = 10;
const int beepButton = 4;

int buttonState = 0;
int buttonBeep = 0;
int times = 0;
int limit = 2;

void setup() {
// put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(startButton, INPUT);  
  pinMode(beepButton, INPUT);  
  pinMode(drill, OUTPUT);
  pinMode(secondPosition, OUTPUT);
  pinMode(fling, OUTPUT);
  pinMode(beep, OUTPUT);
  
  
  Serial.println("POSIÇÃO ORIGINAL...");
  digitalWrite(secondPosition, HIGH);
  digitalWrite(fling, HIGH);
  digitalWrite(drill, HIGH);
  digitalWrite(beep, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int startTime = 0;
  int finishTime = 0;

  buttonState = digitalRead(startButton);
  buttonBeep = digitalRead(beepButton);

  if(buttonBeep == HIGH){
    Serial.println("zerou");
    times = 0;
  }
  if(times == limit) {
    Serial.println("Sirene ON");
    digitalWrite(beep, LOW);
  } else {
    digitalWrite(beep, HIGH);
  }
  if(buttonState == HIGH){
    while(buttonState == LOW){}
    
    startTime= millis();
    
    Serial.println("Start");
    Serial.println("Furo 1");
    digitalWrite(drill, LOW);
    digitalWrite(secondPosition, HIGH);
    digitalWrite(fling, HIGH);
    delay(100);
    digitalWrite(drill, HIGH);
    delay(3500);
    Serial.println("Fim furo 1");
    delay(300);
    Serial.println("Muda posição");
    digitalWrite(secondPosition, LOW);
    delay(300);
    Serial.println("Furo 2");
    digitalWrite(drill, LOW);
    delay(100);
    digitalWrite(drill, HIGH);
    delay(1400);
    Serial.println("Volta posição");
    digitalWrite(secondPosition, HIGH);
    delay(2000);
    Serial.println("Fim furo 2");
    delay(300);
    Serial.println("Ejeta pino");
    digitalWrite(fling, LOW);
    delay(100);
    digitalWrite(fling, HIGH);
    delay(1000);
    Serial.println("Finish");
    times = times+1;
    Serial.println(times);
    
    finishTime = millis() - startTime;
    Serial.println(finishTime);
  }

}
