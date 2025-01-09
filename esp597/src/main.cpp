#include <Arduino.h>

//선언한다 15핀은 myled 선언  15핀을 사용 한다
#define myled 15


void setup() {
  
//led 설정한 핀을 출력으로 설정할것
 pinMode(myled,OUTPUT);

}

void loop() {
 
//led 켠다 
//1초쉰다
//led 끈다
//1쉰다
digitalWrite(myled,HIGH);
delay(1000);
digitalWrite(myled,LOW);
delay(1000);




}
