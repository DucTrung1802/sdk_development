#include <HardwareSerial.h>

HardwareSerial SerialPort(2);  // use UART2


char number = ' ';
int LED = 2;
volatile unsigned long count = 0;

void setup() {
  Serial.begin(115200);
  SerialPort.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  // if (SerialPort.available()) {
  //   String command = SerialPort.readStringUntil('\n');
  //   count++;
  //   Serial.println(command);
  //   if (!(command.compareTo("Hello Chun peo"))) {
  //     Serial.println("Good");
  //   }
  //   Serial.println(count);
  // }

  // String received = "";
  if (SerialPort.available()) {
    char received;
    received = SerialPort.read();
    Serial.print(received);
  }
}