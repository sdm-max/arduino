#include <Arduino.h>


//컴퓨터 쪽으로 특정 문장을 1초간격으로 전송할것



void setup() {
  
  Serial.begin(115200);


}

void loop() {


  Serial.println("나는 사랑 스럽다");
  delay(1000);



}


