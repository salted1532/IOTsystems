#include <Wire.h>                    // I2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>        // I2C LCD 제어를 위한 라이브러리

// LCD 객체 생성 (I2C 주소는 0x27, 16x2 크기의 LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C 주소 0x27, 16컬럼 2행 LCD 사용

void setup()
{
  lcd.begin(16, 2);  // LCD 초기화 (16컬럼 2행 크기 설정)
  lcd.backlight();    // LCD 백라이트 켜기
}

void loop()
{
  lcd.setCursor(5, 0);    // 첫 번째 행, 5번째 열로 커서 이동
  lcd.print("Hi ^^");     // "Hi ^^" 출력

  delay(1000);            // 1초 대기

  lcd.setCursor(3, 1);    // 두 번째 행, 3번째 열로 커서 이동
  lcd.print("Codingrun"); // "Codingrun" 출력

  delay(1000);            // 1초 대기

  lcd.clear();            // LCD 화면을 지움
  delay(1000);            // 1초 대기
}
