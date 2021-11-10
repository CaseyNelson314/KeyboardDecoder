# KeyboardDecoder Library
unti
自作キーボード
# Data
- version   Arduino 1.8.16
- Author    CaseyNelson314
- Date      2021/11/06
# Usage
```
KeyboardDecoder(inputpin);
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
```
# Function list
```
GetNum              引数の数字に対応するスイッチの読み取り値を返す
GetPlus             各記号に対応するスイッチの読み取り値を返す
GetMinus
GetMultiply
GetDivision
GetPlMi
GetBackSpace
GetAC
GetC
GetShift
```
