/*
 * 10/16/2015
 * Mark Chen in Taichung, Taiwan
 *
 */

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int STD_DELAY=13; //連續動作時的delay, 4很快,12很有機器人的慢節奏
int MOVE_DELAY=26; //連續動作時的delay, 4很快,12很有機器人的慢節奏

int LONG_DELAY=0;//每一小動的delay,60 ok

int value=0;

// Arduino Senser Sheld 5.0
int m1Pin=3;
int m2Pin=5;
int m3Pin=6;
int m4Pin=9;

int D90=90;
int m1Min=60;
int m1MinAdj=70;
int m1Max=90;
int m2Min=60;
int m2Max=130;
int m3Min=60;
int m3Max=110;
int m4Min=30;
int m4Max=150;



// 給定的伺服馬達,從 m 運動到 n
// 這兩個值的區間是 0 到180
// 但受到手臂結構限制,不能全部運動
// 因此要一個一個調試
void servoAct(Servo servo,int m, int n){
  if (m<n){
    for (int i=m;i<=n;i++){
      servo.write(i*1);
      delay(STD_DELAY);
    }
  }  
  if (m>n){
    for (int i=m;i>=n;i--){
      servo.write(i*1);
      delay(STD_DELAY);
    }
  } 
 // delay(LONG_DELAY);
}

void m1Close(){
  servoAct(servo1,m1Max,m1Min);//握緊手爪
}
void m1CloseGentle(){
  servoAct(servo1,m1Max,m1Min-20);//握緊手爪
}

void m1Open(){
  servoAct(servo1,m1Min,m1Max);//張開手爪
}
void takeObj(){
  servoAct(servo3,m3Max, m3Min);//底盤起始位置90度,轉到150度的位置  
  servoAct(servo2,m2Min,m2Max);//手臂向前
    delay(500); 
  m1Close(); 
    delay(500); 
  servoAct(servo2,m2Max,m2Min); //手臂回縮  
  servoAct(servo3,m3Min, m3Max);//底盤起始位置90度,轉到150度的位置  
  
}
void putObj(){
 servoAct(servo3,m3Max, m3Min);//底盤起始位置90度,轉到150度的位置  
   servoAct(servo2,m2Min,m2Max);//手臂向前
    delay(500); 
  m1Open();  
  delay(500);
  servoAct(servo2,m2Max,m2Min); //手臂回縮  
  servoAct(servo3,m3Min, m3Max);//底盤起始位置90度,轉到150度的位置  
 
}

void putObjHigh(){
//  servoAct(servo3,D90,m3Min);//底盤起始位置90度,轉到150度的位置  
  servoAct(servo2,D90,m2Max);//手臂向前
  servoAct(servo3,D90,m3Max);//  

    delay(500); 
  m1Open();  
  delay(500);
  servoAct(servo3,m3Max,D90);//  

  servoAct(servo2,m2Max,D90); //手臂回縮  
//  servoAct(servo3,m3Min,D90);//底盤起始位置90度,轉到150度的位置  

}


// add different high
void combo3(){
  // move left to middle
  //servoAct(servo3,D90,m3Max);
  
  servoAct(servo4,D90,m4Max);//底盤起始位置90度,轉到150度的位置  
  takeObj();  
  servoAct(servo4,m4Max,D90);//底盤位置回到90度,
  putObjHigh();


 return;
  
 // move right to left
  servoAct(servo4,D90,m4Min);//底盤起始位置90度,轉到150度的位置  
  takeObj();  
  servoAct(servo4,m4Min,m4Max);//底盤起始位置90度,轉到150度的位置
  putObj();

  // move middle to right
  servoAct(servo4,m4Max,D90);//底盤起始位置90度,轉到150度的位置  
  takeObj();  
  servoAct(servo4,D90, m4Min);//底盤起始位置90度,轉到150度的位置
  putObj();

  servoAct(servo4,m4Min,D90);//底盤起始位置90度,轉到150度的位置
  

 // servoAct(servo3,m3Max,D90);
  

  

  
} 
void combo2Adj(){
  servoAct(servo2,90,m2Min);
  servoAct(servo3,90,m3Max);
  combo2();
  servoAct(servo3,m3Max,90);
  servoAct(servo2,m2Min,90);
  
}

// 這是組合的範例
void combo2(){
  // move left to middle
  //servoAct(servo3,D90,m3Max);
  
  servoAct(servo4,D90,m4Max);//底盤起始位置90度,轉到150度的位置  
  takeObj();  
  servoAct(servo4,m4Max,D90);//底盤起始位置90度,轉到150度的位置
  putObj();


 // return;
  
 // move right to left
  servoAct(servo4,D90,m4Min);//底盤起始位置90度,轉到150度的位置  
  takeObj();  
  servoAct(servo4,m4Min,m4Max);//底盤起始位置90度,轉到150度的位置
  putObj();

  // move middle to right
  servoAct(servo4,m4Max,D90);//底盤起始位置90度,轉到150度的位置  
  takeObj();  
  servoAct(servo4,D90, m4Min);//底盤起始位置90度,轉到150度的位置
  putObj();

  servoAct(servo4,m4Min,D90);//底盤起始位置90度,轉到150度的位置
  

 // servoAct(servo3,m3Max,D90);
  

  

  
} 

void combo1(){
  servoAct(servo4,D90,m4Max);//底盤起始位置90度,轉到150度的位置
  //delay(MOVE_DELAY);
  servoAct(servo1,D90,m1Max);//張開手爪
  servoAct(servo2,D90,m2Max);//手臂向前
  servoAct(servo1,m1Max,m1Min);//握緊手爪  
  servoAct(servo2,m2Max,D90); //手臂回縮
   
  servoAct(servo4,m4Max,m4Min);//底盤轉到90度的位置
  //servoAct(servo4,90,30); //底盤轉到30度的位置
    
  servoAct(servo2,D90,m2Max);//手臂向前
  servoAct(servo1,m1Min,m1Max);//張開手爪
  servoAct(servo2,m2Max,D90);//手臂回縮
  servoAct(servo1,m1Max,D90);//手爪 default
  
  servoAct(servo4,m4Min,D90); //底盤轉到90度的起始位置 
} 
int TEST_DEALY=100;
void testServo1(){
  servoAct(servo1,90,m1Min);
  delay(TEST_DEALY);
  servoAct(servo1,m1Min,90);
  delay(TEST_DEALY);
//  servoAct(servo1,90,110);
//  servoAct(servo1,110,90);
  
}
void testServo2(){
  servoAct(servo2,90,120);
  delay(TEST_DEALY);
  servoAct(servo2,120,90);    
  delay(TEST_DEALY);
}
void testServo3(){
  servoAct(servo3,90,m3Max);
  delay(TEST_DEALY);
  servoAct(servo3,m3Max,90);    
  delay(TEST_DEALY);
  servoAct(servo3,90,m3Min);
  delay(TEST_DEALY);
  servoAct(servo3,m3Min,90);    
  delay(TEST_DEALY);
}
void testServo4(){
  servoAct(servo4,90,45);
  delay(500);
  servoAct(servo4,45,90);    
  delay(500);
  servoAct(servo4,90,135);
  delay(500);
  
  servoAct(servo4,135,90);    
  delay(500);
}





void setup() {
 
  servo1.attach(m1Pin); // 手爪
  servo2.attach(m2Pin); // 前後
  servo3.attach(m3Pin); // 上下
  servo4.attach(m4Pin); // 底盤
  

 

  for (int k=0;k<1;k++){
//    單獨伺服馬達測試
//    testServo1();
//    testServo2();
//    testServo3();
//  testServo4(); 

    //組合展示一:機械手臂到左旁拿東西放到右邊
   combo2Adj();
//    m1CloseGentle();
//     putObjHigh();

  }
}

void loop() {
  // 另案開發,此處空白
}
