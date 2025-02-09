//JSON데이터를 역직렬화하기위해서 필요함!
#include <ArduinoJson.h>

#define led1 2 //led1번은 디지털2번핀에 연결함!
#define led2 3 //led2번은 디지털3번핀에 연결함!

void setup() {
  //파이썬과 통신속도가 9600이다!(보-레이트가 9600이다)
  Serial.begin(9600);
  //led가 연결된 핀의 방향을 설정한다
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  //파이썬에서 JSON데이터가 수신되면 종료문자인 \n이 있을때까지 읽는다!
  if(Serial.available() > 0){
    //아두이노의 수신버퍼에 데이터가 존재할경우 \n까지읽어서 myjson에 반환한다!
    String myjson = Serial.readStringUntil('\n');
    //myjson : 파이썬이 보낸 JSON데이터임!(역직렬화해볼까?)

    //일단 비어있는 object를 적정한 사이트에 맞게 만들어줌!
    StaticJsonDocument<48> doc;

    //파이썬에서 수신한 json을 역직렬화해서 doc에 대입해줌!
    DeserializationError error = deserializeJson(doc, myjson);

    //파이썬쪽에서 json규칙에 위배되는 데이터를 전송하는 경우 에러임!
    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
