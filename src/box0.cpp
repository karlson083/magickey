/*   Данный скетч делает следующее: 
*/

#include "SPI.h"
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9, 10);  // "создать" модуль на пинах 9 и 10 Для Уно
byte counter;

void setup() {
  Serial.begin(9600);         // открываем порт для связи с ПК
  pinMode(2, INPUT_PULLUP);
  radio.begin();              // активировать модуль
  //radio.setAutoAck(0);        // режим подтверждения приёма, 1 вкл 0 выкл
  //radio.setRetries(0, 15);    // (время между попыткой достучаться, число попыток)
  //radio.enableAckPayload();   // разрешить отсылку данных в ответ на входящий сигнал
  //radio.enableDynamicAck();                                  // Разрешаем выборочно отключать запросы подтверждения приема данных.
  radio.setPayloadSize(32);   // размер пакета, в байтах
  radio.openWritingPipe(0x0x7878787878LL);  // мы - труба 0, открываем канал для передачи данных
  radio.openReadingPipe (0, 0x7878787878LL); // Открываем 0 трубу с адресом 2 передатчика 0xAABBCCDD22, для приема данных.
  radio.openReadingPipe (1, 0xAABBCCDD11LL); // Открываем 1 трубу с адресом 2 передатчика 0xAABBCCDD22, для приема данных.
  radio.openReadingPipe (2, 0xAABBCCDD22LL); // Открываем 2 трубу с адресом 2 передатчика 0xAABBCCDD22, для приема данных.
  radio.openReadingPipe (3, 0xAABBCCDD33LL); // Открываем 3 трубу с адресом 2 передатчика 0xAABBCCDD22, для приема данных.
  radio.openReadingPipe (4, 0xAABBCCDD44LL); // Открываем 4 трубу с адресом 2 передатчика 0xAABBCCDD22, для приема данных.
  radio.openReadingPipe (5, 0xAABBCCDD55LL); // Открываем 5 трубу с адресом 2 передатчика 0xAABBCCDD22, для приема данных.
  radio.setChannel(0x60); // выбираем канал (в котором нет шумов!)
  //radio.setAutoAck( false );
  radio.setPALevel (RF24_PA_MAX); // уровень мощности передатчика. На выбор RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate (RF24_2MBPS); // скорость обмена. На выбор RF24_2MBPS, RF24_1MBPS, RF24_250KBPS
                                  //должна быть одинакова на приёмнике и передатчике!
                                  //при самой низкой скорости имеем самую высокую чувствительность и дальность!!

  radio.powerUp();        // начать работу
  radio.startListening(); // начинаем слушать эфир, мы приёмный модуль
}

void loop(){  
  byte pipeNo, gotByte;          
    if(radio.available(&pipeNo)){                                // Если в буфере имеются принятые данные, то получаем номер трубы по которой эти данные пришли в переменную pipe.
        radio.read( &gotByte, sizeof(gotByte) );                 // Читаем данные из буфера в массив gotByte указывая сколько всего байт может поместиться в массив.
        if(pipeNo==0){ /* Данные пришли по 0 трубе */ 
                      radio.stopListening   ();                              // Выключаем приёмник, завершаем прослушивание открытых труб.
                      Serial.print("Recieved 0 : ");
                      Serial.println(gotByte);
                      delay(500);
                      radio.startListening(); // начинаем слушать эфир, мы приёмный модуль
                  }         // Если данные пришли от 0 передатчика (по 0 трубе), то можно выполнить соответствующее действие ...
        if(pipeNo==1){ /* Данные пришли по 1 трубе */ 
                      radio.stopListening   ();                              // Выключаем приёмник, завершаем прослушивание открытых труб.
                      Serial.print("Recieved 1 : ");
                      Serial.println(gotByte);
                      delay(500);
                      radio.startListening(); // начинаем слушать эфир, мы приёмный модуль
                  }         // Если данные пришли от 1 передатчика (по 1 трубе), то можно выполнить соответствующее действие ...
        if(pipeNo==2){ /* Данные пришли по 2 трубе */ 
                      radio.stopListening   ();                              // Выключаем приёмник, завершаем прослушивание открытых труб.
                      Serial.print("Recieved 2 : ");
                      Serial.println(gotByte);
                      delay(500);
                      radio.startListening(); // начинаем слушать эфир, мы приёмный модуль
                  ;
                  }         // Если данные пришли от 2 передатчика (по 2 трубе), то можно выполнить соответствующее действие ...
        if(pipeNo==3){ /* Данные пришли по 3 трубе */ 
                      radio.stopListening   ();                              // Выключаем приёмник, завершаем прослушивание открытых труб.
                      Serial.print("Recieved 3 : ");
                      Serial.println(gotByte);
                      delay(500);
                      radio.startListening(); // начинаем слушать эфир, мы приёмный модуль
                  ;
                  }         // Если данные пришли от 3 передатчика (по 3 трубе), то можно выполнить соответствующее действие ...
        if(pipeNo==4){ /* Данные пришли по 4 трубе */ 
                      radio.stopListening   ();                              // Выключаем приёмник, завершаем прослушивание открытых труб.
                      Serial.print("Recieved 4 : ");
                      Serial.println(gotByte);
                      delay(500);
                      radio.startListening(); // начинаем слушать эфир, мы приёмный модуль
                  ;
                  }         // Если данные пришли от 4 передатчика (по 4 трубе), то можно выполнить соответствующее действие ...                  
        if(pipeNo==5){ /* Данные пришли по 3 трубе */ 
                      radio.stopListening   ();                              // Выключаем приёмник, завершаем прослушивание открытых труб.
                      Serial.print("Recieved 5 : ");
                      Serial.println(gotByte);
                      delay(500);
                      radio.startListening(); // начинаем слушать эфир, мы приёмный модуль
                  ;
                  }         // Если данные пришли от 5 передатчика (по 5 трубе), то можно выполнить соответствующее действие ...
        
    }
      if (!digitalRead(2)) {
          radio.stopListening   ();                              // Выключаем приёмник, завершаем прослушивание открытых труб.
          Serial.print("Sent: ");
          Serial.println(counter);
          radio.write(&counter, sizeof(counter));
          counter++;
          //delay(3000);
          radio.startListening(); // начинаем слушать эфир, мы приёмный модуль
  }
} 