/// приемник с реле
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#define MAX_CHANNELS 14
int ch;
int chVal[MAX_CHANNELS] = {0};
int            data[MAX_CHANNELS];
RF24 radio(7, 8);

RF24Network network(radio);


#define ID 02 // ID устройства
//****************Переменные пинов светодиодов
int l1 = 1;
int l2 = 2;
int l3 = 19;
int l4 = 4;
int l5 = 5;
int l6 = 6;
int l7 = 9;
int l8 = 10;
int l9 = 14;
int l10 = 15;
int l11 = 16;
int l12 = 17;
int l13 = 18;
int l14 = 3;
//**************************
int lp[] = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14}; // массив пинов светодиодов

const char inv_off = LOW ;   //LOW для макета, HIGH для костюма с транзисторами
const char inv_on = HIGH ;  // HIGH для макета, LOW для костюма с транзисторами

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