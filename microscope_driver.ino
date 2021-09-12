#include <CheapStepper.h>
#include <string.h>

CheapStepper stepper1( 2,3,4,5 );
CheapStepper stepper2( 6,7,8,9 );
CheapStepper stepper3( 10,11,12,13 );

String serial_input; 

void setup() {
  Serial.begin(9600);
  stepper1.setRpm(16);
  stepper2.setRpm(16);
  stepper3.setRpm(16);
  while (!Serial) {
    ; // wait for serial port to connect
  }
};

void loop() {
  if (Serial.available()) {
    serial_input = Serial.readString();
    if (serial_input.startsWith("a")) {
      serial_input.remove(0, 1);
      if (serial_input.startsWith("+")) {
        serial_input.remove(0, 1);
        stepper1.stop();
        stepper1.newMove(false, serial_input.toInt());
      };
      if (serial_input.startsWith("-")) {
        serial_input.remove(0, 1);
        stepper1.stop();
        stepper1.newMove(true, serial_input.toInt());
      };
    };
    if (serial_input.startsWith("b")) {
      serial_input.remove(0, 1);
      if (serial_input.startsWith("+")) {
        serial_input.remove(0, 1);
        stepper2.stop();
        stepper2.newMove(false, serial_input.toInt());
      };
      if (serial_input.startsWith("-")) {
        serial_input.remove(0, 1);
        stepper2.stop();
        stepper2.newMove(true, serial_input.toInt());
      };
    };
    if (serial_input.startsWith("c")) {
      serial_input.remove(0, 1);
      if (serial_input.startsWith("+")) {
        serial_input.remove(0, 1);
        stepper3.stop();
        stepper3.newMove(false, serial_input.toInt());
      };
      if (serial_input.startsWith("-")) {
        serial_input.remove(0, 1);
        stepper3.stop();
        stepper3.newMove(true, serial_input.toInt());
      };
    };
  };
  stepper1.run();
  stepper2.run();
  stepper3.run();
};