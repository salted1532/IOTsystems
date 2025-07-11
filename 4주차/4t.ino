// 핀 정의
int LED11 = 11;   // 0-5cm일 때 LED11
int LED12 = 12;   // 6-10cm일 때 LED12
int LED13 = 13;   // 11-15cm일 때 LED13

// 초음파 센서 핀 정의
int trigPin = 5;
int echoPin = 4;

void setup() {
  // 시리얼 통신 시작
  Serial.begin(9600);
  
  // 핀 모드 설정
  pinMode(LED11, OUTPUT);
  pinMode(LED12, OUTPUT);
  pinMode(LED13, OUTPUT);
  
  pinMode(trigPin, OUTPUT);  // 초음파 센서 트리거 핀 설정
  pinMode(echoPin, INPUT);   // 초음파 센서 에코 핀 설정
}

void loop() {
  // 초음파 센서로 거리 측정
  long distance = getDistance();  // 초음파 센서로 거리 측정 (cm)

  // 초음파 센서 거리 값에 따라 LED 제어
  if (distance >= 0 && distance <= 5) {
    // 0 ~ 5cm일 때 LED11 켜기
    digitalWrite(LED11, HIGH);
    digitalWrite(LED12, LOW);
    digitalWrite(LED13, LOW);
  } else if (distance >= 6 && distance <= 10) {
    // 6 ~ 10cm일 때 LED12 켜기
    digitalWrite(LED11, LOW);
    digitalWrite(LED12, HIGH);
    digitalWrite(LED13, LOW);
  } else if (distance >= 11 && distance <= 15) {
    // 11 ~ 15cm일 때 LED13 켜기
    digitalWrite(LED11, LOW);
    digitalWrite(LED12, LOW);
    digitalWrite(LED13, HIGH);
  } else {
    // 그 외의 거리일 때 모든 LED 끄기
    digitalWrite(LED11, LOW);
    digitalWrite(LED12, LOW);
    digitalWrite(LED13, LOW);
  }

  delay(500);  // 0.5초 대기
}

// 초음파 센서 거리 측정 함수 (라이브러리 없이)
long getDistance() {
  // 초음파 센서로 거리를 측정하는 함수
  // 트리거 핀에 짧은 펄스를 주어 초음파를 발사합니다.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  // 짧은 시간 대기
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // 10마이크로초 동안 트리거 신호를 HIGH로 설정
  digitalWrite(trigPin, LOW);

  // 에코 핀에서 반사된 신호를 받습니다.
  long duration = pulseIn(echoPin, HIGH); // 신호가 돌아오는 시간을 마이크로초로 측정

  // 거리 계산: 거리 = (시간 * 속도) / 2, 속도는 약 343m/s
  long distance = duration * 0.0344 / 2;  // cm로 변환

  return distance;  // 거리 반환  
}
