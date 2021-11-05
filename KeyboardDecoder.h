/*
        @file   KeyboardDecoder.h
        @brief  keyboard
        @author CaseyNelson314
        @date   2021/11/06
*/
/*
  -------------------------
  | AC  |  C  |SHIFT|  /  |
  -------------------------
  |  7  |  8  |  9  |  *  |
  -------------------------
  |  4  |  5  |  6  |  +  |
  -------------------------
  |  1  |  2  |  3  |  -  |
  -------------------------
  |  ±  |  0  |BackS|  =  |
  -------------------------
*/
#pragma once
#include <Arduino.h>

class KeyboardDecoder {

  private:
    byte DelayTime;
    byte inputpin;
    int  input;
    bool Olddata[20];
    bool Clickdata[20];
    unsigned long Time, OldTime;

  public:
    KeyboardDecoder(byte INPUTPIN): inputpin(INPUTPIN) {}

    void Update() {
      if ((Time = millis()) - OldTime > DelayTime) {
        input = analogRead(inputpin);
        int  analogtable[21] = {24, 73, 121, 168, 214, 259, 304, 349, 394, 440, 486, 534, 583, 633, 685, 740, 797, 857, 921, 988, 1023};
        for (int i = 0; i < 20; i++) Clickdata[i] = !Olddata[i] * (Olddata[i] = (analogtable[i] < input) * (input <= analogtable[i + 1]));
        OldTime = Time;
      }
    }

    void ChattBlock(int DELAYTIME) {
      DelayTime = DELAYTIME;
    }

    bool GetNum(byte RequestNum) {
      byte swtable[10] = {17, 12, 13, 14, 8, 9, 10, 4, 5, 6};
      return Clickdata[swtable[RequestNum]];
    }

    bool GetPlus() {      //+
      return Clickdata[11];
    }
    bool GetMinus() {     //-
      return Clickdata[17];
    }
    bool GetMultiply() {  //*
      return Clickdata[7];
    }
    bool GetDivision() {  ///
      return Clickdata[3];
    }
    bool GetDivision() {     //=
      return Clickdata[19];
    }
    bool GetPlMi() {      //±
      return Clickdata[16];
    }
    bool GetBackSpace() { //backspace
      return Clickdata[18];
    }
    bool GetAC() {        //AC
      return Clickdata[0];
    }
    bool GetC() {         //C
      return Clickdata[1];
    }
    bool GetShift() {     //Shift
      return Clickdata[2];
    }

};
