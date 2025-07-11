#include <Servo.h> // Servo 라이브러리 추가

Servo servo;  // Servo 클래스로 servo 객체 생성
int value = 0; // 각도를 조절할 변수 value

// LED 제어를 위한 핀 설정
int redPin = 5;
int greenPin = 6;
int bluePin = 7;

void setup() {
  servo.attach(9);    // 핀 7에 서보 모터 연결
  Serial.begin(9600); // 시리얼 모니터 사용
  
  // LED 핀을 출력으로 설정
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (Serial.available()) {    // 시리얼 모니터에 데이터가 입력되면
    char in_data;              // 입력된 데이터를 담을 변수 in_data
    in_data = Serial.read();   // 시리얼 모니터로 입력된 데이터를 in_data에 저장

    if (in_data == '1') {      // 입력된 데이터가 '1'이라면
      value += 30;             // 각도를 30도 증가시킨다.
      if (value >= 210) {      // 각도가 210도가 되면 (180도보다 커지면)
        value = 0;             // 각도를 0으로 초기화
      }
    }
    else {                     // 그 외의 데이터가 입력되면
      value = 0;               // 각도를 0으로 초기화
    }

    servo.write(value); // value 값의 각도로 서보 회전

    // 각도에 따라 LED 색상 변경
    if (value % 10 == 0) {  // 10도 단위로 색 변경
      if (value == 0) {
        setColor(255, 0, 0); // 빨간색
      } else if (value == 90) {
        setColor(0, 0, 255); // 파란색
      } else if (value == 180) {
        setColor(0, 255, 0); // 연두색
      } else {
        setColor(255, 255, 0); // 노란색 (기본값)
      }
    }
  }
}

// LED 색상을 설정하는 함수
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
