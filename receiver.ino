#include <SPI.h>
#define MAX_CHANNELS 14
byte ch;
byte chVal[MAX_CHANNELS] = {0};
byte data[MAX_CHANNELS];


#define ID 02 // ID устройства  // <<<<<< не 02, а 2, т.к. ведущий ноль переводит счисление в бинарное,
//****************Переменные пинов светодиодов
const byte l1 = 1;
const byte l2 = 2;
const byte l3 = 19;
const byte l4 = 4;
const byte l5 = 5;
const byte l6 = 6;
const byte l7 = 9;
const byte l8 = 10;
const byte l9 = 14;
const byte l10 = 15;
const byte l11 = 16;
const byte l12 = 17;
const byte l13 = 18;
const byte l14 = 3;
//**************************
const byte lp[] = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14}; // массив пинов светодиодов

const boolean inv_off = LOW ;   //LOW для макета, HIGH для костюма с транзисторами
const boolean inv_on = HIGH ;  // HIGH для макета, LOW для костюма с транзисторами

void setup(void)
{
  //Serial.begin(57600);

  for (int i = 0; i < 14; i++) {
    pinMode(lp[i], OUTPUT);
    digitalWrite(lp[i], inv_on);
  }


  SPI.begin();
  radio.begin();
  network.begin(/*channel*/ 90, /*node address*/ ID);
  //radio.setAutoAck(false); // отключаем подтверждение приема пакетов
}

void loop(void)
{
  // Pump the network regularly
  network.update();                                        // нужно постоянно запускать, чтобы транслировались
  // данные между узлами

  // Is there anything ready for us?
  while ( network.available() )                            // если пришли данные
  {
    // If so, grab it and print it out
    RF24NetworkHeader header;

    network.read(header, &data, sizeof(data));             // читаем данные
    //Serial.println(data);                                  // отправляем в сериал для отладки
    for (ch = 0; ch < MAX_CHANNELS; ch++) {
      //digitalWrite(relayPin,!digitalRead(relayPin));
      //Serial.print(data[ch]);
      //Serial.print("  ");
      digitalWrite(lp[ch], !data[ch]);
    }

    // Serial.println("  ");
    // Serial.println("______________________________________");


    //digitalWrite(l1, !data[0]);
    //digitalWrite(l2, !data[1]);
    //digitalWrite(l3, !data[2]);
    //digitalWrite(l4, !data[3]);
    //analogWrite(l5, data[4]);
    //analogWrite(l6, data[5]);
    //analogWrite(l7, data[6]);
    //analogWrite(l8, data[7]);
    //digitalWrite(l9, !data[8]);
    //digitalWrite(l10, !data[9]);
    //digitalWrite(l11, !data[10]);
    //digitalWrite(l12, !data[11]);
    //digitalWrite(l13, !data[12]);
    //analogWrite(l14, data[13]);
  }


}