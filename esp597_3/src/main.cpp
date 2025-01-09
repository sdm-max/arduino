#include <Arduino.h>

//led가 15번핀에 연결되어있고 
//버튼이 5번핀에 연결되었을때 코드작성

#define myled 15
#define mybut 5


void setup() {

  //핀의 방향 지정
  pinMode(myled,OUTPUT);
  //esp32의 내부 풀업저항을 이용해서 버튼을 인식시키는 방법
  //주의 모든 디지털핀에 풀업저항이 걸려있는게 아니다 풀업 저항이 걸려있는 핀을 찾아서 꼽아야한다
  pinMode(mybut,INPUT_PULLUP);



}

void loop() {
  
//버튼이 안눌려지면 high, 버튼이 눌려지면 low 신호가 나온다 
//esp32는 핀을 검수할수있다
bool btn_state = digitalRead(mybut);

switch (btn_state)
{
case HIGH/* constant-expression */:
  /* code */
  digitalWrite (myled,LOW);
  break;

  case LOW:
  digitalWrite (myled,HIGH);

default:
  break;
}



//만약에 버튼이 눌러지면 led를 켜고
//안눌려지면 led를 끈다


}


