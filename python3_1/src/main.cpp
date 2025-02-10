// 파이썬 데이터를 역직령화 하기 위한 라이브러리
#include <ArduinoJson.h>

#define LED1 2 // LED 1번 핀 디지털 2번핀에 연결함
#define LED2 3 // LED 2번 핀 디지털 3번핀에 연결함
void setup() {
  //파이썬과 통신 속도는 9600으로 설정
  Serial.begin(9600);
  //LED가 연결된 핀의 방향을 설정한다
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  //파이썬에서 데이터가 들어오면 종료문자인 /n을 만날때까지 데이터를 읽어옴
  if(Serial.available() > 0) {

    //아두이노의 수신버퍼에 데이터가 있으면 데이터를 읽어옴 /n을 만날때까지 데이터를 읽어옴
    String myjson = Serial.readStringUntil('\n');

    // myjson : 파이썬이 보낸 json 데이터 역직렬화 하기
    // 비어있는 object를 생성 사이트에 맞추서 96으로 설정
      // JSON 문서를 파싱할 객체 생성
    StaticJsonDocument<96> doc;

    // 파이썬에서 수신한 json 데이터를 역직렬화해서 doc에 대입
      // JSON 데이터 파싱
  DeserializationError error = deserializeJson(doc, myjson);
    
    // 파이썬쪽에서 json 규칙에 위배되는 데이터를 보내면 에러를 출력
    // 파싱 오류 확인
  // 역직렬화 오류가 발생했는지 확인
    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    // 원문 myjson = {"key1":"value1","key2":"value2","key3":"value3"}
    // 역설겨된 myjson을 doc에 대입하면 아래처럼 사용가능
    int led_num = doc["led_num"]; // 1
    int state = doc["state"]; // 0

    if(led_num == 0){
      //모든 led 제어하기
      if(state == 0){
        //끄기
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
      }else if(state == 1){
        //켜기
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,HIGH);
      }
    }else if(led_num == 1){
      //led 1번 제어하기
      if(state == 0){
        //끄기
        digitalWrite(LED1,LOW);
      }else if(state == 1){
        //켜기
        digitalWrite(LED1,HIGH);
      }
    }else if(led_num == 2){
      //led 2번 제어하기
      if(state == 0){
        //끄기
        digitalWrite(LED2,LOW);
      }else if(state == 1){
        //켜기
        digitalWrite(LED2,HIGH);
      }
    }    
  }
}