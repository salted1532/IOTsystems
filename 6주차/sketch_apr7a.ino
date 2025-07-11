#define TRIGGER_PIN 5 //초음파 트리거
#define ECHO_PIN 6 //초음파 에코
#define MAX_DISTANCE 30 // 최대 거리 초음파

#define LED_R_PIN 13 //빨간색
#define LED_G_PIN 12 //초록색
#define LED_B_PIN 11 //파란색

#define BUZZER_PIN 7 //피오조 스피커 핀

void setup() {
  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600); //시리얼 모니터 설정
}

void loop() {
  delay(50);

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.0344 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance >= 0 && distance <= 10) {
    digitalWrite(LED_R_PIN, HIGH);
    digitalWrite(LED_G_PIN, LOW);
    digitalWrite(LED_B_PIN, LOW);
    Serial.println("Executing playFurElise()");
    playFurElise();
  }
  else if(distance >= 11 && distance <= 20) {
    digitalWrite(LED_R_PIN, LOW);
    digitalWrite(LED_G_PIN, HIGH);
    digitalWrite(LED_B_PIN, LOW);
    Serial.println("Executing playFurElise()");
    playFurElise();
  }
  else if(distance >= 21 && distance <= 30) {
    digitalWrite(LED_R_PIN, LOW);
    digitalWrite(LED_G_PIN, LOW);
    digitalWrite(LED_B_PIN, HIGH);
    Serial.println("Executing playHandInHand()");
    playHandInHand();
  }
  else {
    Serial.println("Out of range");
  }
}

void playWaringTone() {
  tone(BUZZER_PIN, 1000);
  delay(500);
  noTone(BUZZER_PIN);
  delay(500);
  Serial.println("Executing playWaringTone()");
}

void playFurElise() {
  int melody[] = {
    440,440,466,440,523,493,440,466,440,523,493,440,440,466,440,523,493
  };
  int duration[] = {
    500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500
  };

  for(int i = 0; i< 17; i++) {
    tone(BUZZER_PIN, melody[i]);
    delay(duration[i]);
    noTone(BUZZER_PIN);
    delay(50);
  }
  Serial.println("Finished Executing playFurElise()");
}

void playHandInHand() {
  int melody[] = {
    262,262,294,294,330,330,349,392,392,440,440
  };
  int duration[] = {
    500,500,500,500,500,500,500,500,500,500,500
  };

  for(int i = 0; i< 12; i++) {
    tone(BUZZER_PIN, melody[i]);
    delay(duration[i]);
    noTone(BUZZER_PIN);
    delay(50);
  }
  Serial.println("Finished Executing playHandInHand()");
}
