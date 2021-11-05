#include "KeyboardDecoder.h"
KeyboardDecoder key(A0);

void setup() {
  Serial.begin(115200);
  key.ChattBlock(0);
}

void loop() {
  key.Update();
}
