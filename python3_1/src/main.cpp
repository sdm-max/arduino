// 파이썬 데이터를 역직령화 하기 위한 라이브러리
#include <ArduinoJson.h>

void setup() {
  //파이썬과 통신 속도는 9600으로 설정
  Serial.begin(9600);

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
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

    // 원문 myjson = {"key1":"value1","key2":"value2","key3":"value3"}
    // 역설겨된 myjson을 doc에 대입하면 아래처럼 사용가능
  String key1 = doc["key1"]; // "value1"
  String key2 = doc["key2"]; // "value2"
  String key3 = doc["key3"]; // "value3"

    // 추출한 값 출력
    Serial.print("key1=");
    Serial.print(key1);
    Serial.print(",key2=");
    Serial.print(key2);
    Serial.print(",key3=");
    Serial.print(key3);
    Serial.println();


  }
}

