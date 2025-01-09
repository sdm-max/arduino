#include <Arduino.h>

//15번핀에 연결된 LED를 1초간격으로 깜빡이게 하여라!
//나의 LED가 15번핀에 연결되었는데 15라고 쓰면 뭔가 멋이없으니
//myled라는 별명을 붙혀주겠다!
#define myled 15

void setup() {
  //LED가 연결된 핀을 출력으로 설정할 것
  pinMode(myled,OUTPUT);
}

void loop() {
  //LED를 켠다
  digitalWrite(myled,HIGH);
  //1초쉰다
  delay(1000);
  //LED를 끈다
  digitalWrite(myled,LOW);
  //1초쉰다
  delay(1000);
}
