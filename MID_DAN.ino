#include <ATX2.h>  // ATX2 Board
int CFLB=574,CMG,CFRB=610,CBLB=621,CBRB=609;
int x;
void setup() {
  XIO();
  OK();
  glcdClear();
 beep(); delay(10000);
GO2(); CF(); TurnL();  CB(); GO(); CF(); TurnL(); CB(); GO2(); GG();
  
}

void loop() {
 
}

void Glcd(){ setTextSize(1);
  glcd(0, 1, "FLB= %d ", analog (0));  
   glcd(2, 1, "FRB= %d ", analog (1));
  glcd(1, 1, "MG= %d ", analog (2)); 
  glcd(3, 1, "BLB= %d ", analog (3)); {}
  glcd(5, 1, "BRB= %d ", analog(4));
}

void motorU(int FL ,int FR){
  motor(1,FL);
  motor(2,FR);
  motor(3,FL);
  motor(4,FR);
  }

void GO(){
  motorU(80,80);
  delay(700);
  AO(); delay(50);
}

void GO2(){
   motorU(80,80);
  delay(700);
  AO(); delay(50);
  motorU(80,80);
  delay(700);
  AO(); delay(50);
  }

void GO3(){
   motorU(80,80);
  delay(700);
  AO(); delay(50);
  motorU(80,80);
  delay(700);
  AO(); delay(50);
  motorU(80,80);
  delay(700);
  AO(); delay(50);
  }

void TurnL(){
  AO(); delay(30);
  motorU(-30,30);   delay(850);
  AO(); delay(30);
  }

void TurnR(){
  AO();delay(30);
  motorU(-20,20); delay(300);
  AO(); delay(30);
  
  }

void spinL(){
    AO(); delay(30);
  motorU(20,-20); delay(500);
  AO(); delay(30);
 }

void spinR(){
  AO(); delay(30);
  motorU(-20,20); delay(500);
  AO(); delay(30);
  }

  
void GG()  // วางกระป๋อง
{ 
  while(analog(0) > CFLB && analog(1) > CFRB) {motorU(30,30);}    //เดินหน้า
  while(analog(0) < CFLB && analog(1) > CFRB) {motorU(-20,20);}                          //หน้าซ้ายเจอดำ เบี่ยงขวาเพื่อตรง
  while(analog(0) > CFLB && analog(1) < CFRB) {motorU(20,-20);}                          //หน้าขวาเจอดำ เบี่ยงซ้ายเพื่อตรง
  if(analog(0) > CFLB && analog(1) > CFRB) {AO();delay(250);}      //เจอเส้นดำหยุด
 beep(); delay(10);
  servo(1,180);  
  sleep(450);    
  servo(1,100); 
  sleep(450);  
  servo(1,-1);
}



void CF(){
 while(analog(0) > CFLB  &&  analog(1) > CFRB){motorU(10,10);}
 while(analog(0) < CFLB && analog(1) > CFRB){motorU(-50,50);}
 while(analog(0) > CFLB && analog(1) < CFRB){motorU(50,-50);}
 if(analog(0)<CFLB && analog(1)<CFRB){AO(); delay(30);}  
 motorU(-50,-50); delay(400);
 AO(); delay(30);
}

void CFL(){
 while(analog(0) > CFLB  &&  analog(1) > CFRB){motorU(30,30);}
 while(analog(0) < CFLB && analog(1) > CFRB){motorU(-50,50);}
 while(analog(0) > CFLB && analog(1) < CFRB){motorU(50,-50);}
 if(analog(0)<CFLB && analog(1)<CFRB){AO(); delay(30);}  
 motorU(-50,-50); delay(500);
 AO(); delay(30);
 motorU(-50,50); delay(100);
 AO(); delay(50);
}

void CFR(){
 while(analog(0) > CFLB  &&  analog(1) > CFRB){motorU(30,30);}
 while(analog(0) < CFLB && analog(1) > CFRB){motorU(-50,50);}
 while(analog(0) > CFLB && analog(1) < CFRB){motorU(50,-50);}
 if(analog(0)<CFLB && analog(1)<CFRB){AO(); delay(30);}  
 motorU(-50,-50); delay(500);
 AO(); delay(30);
 motorU(50,-50); delay(100);
 AO(); delay(50);
}

void CB(){
 while(analog(3) > CBLB  &&  analog(4) > CBRB){motorU(-30,-30);}
 while(analog(3) < CBLB && analog(4) > CBRB){motorU(50,-50);}
 while(analog(3) > CBLB && analog(4) < CBRB){motorU(-50,50);}
 if(analog(3)<CBLB && analog(4)<CBRB){AO(); delay(30);}  
 motorU(50,50); delay(200);
 AO(); delay(30);
}

void CBL(){
 while(analog(3) > CBLB  &&  analog(4) > CBRB){motorU(-30,-30);}
 while(analog(3) < CBLB && analog(4) > CBRB){motorU(50,-50);}
 while(analog(3) > CBLB && analog(4) < CBRB){motorU(-50,50);}
 if(analog(3)<CBLB && analog(4)<CBRB){AO(); delay(30);}  
 motorU(50,50); delay(500);
 AO(); delay(30);
 motorU(-50,50);  delay(500);
 AO(); delay(30);
}

void CBR(){
 while(analog(3) > CBLB  &&  analog(4) > CBRB){motorU(-30,-30);}
 while(analog(3) < CBLB && analog(4) > CBRB){motorU(50,-50);}
 while(analog(3) > CBLB && analog(4) < CBRB){motorU(-50,50);}
 if(analog(3)<CBLB && analog(4)<CBRB){AO(); delay(30);}  
 motorU(50,50); delay(500);
 AO(); delay(30);
 motorU(50,-50);  delay(500);
 AO(); delay(30);
}



void servom()  {
  x = knob(180); //0,540
  servo(1, x);
  glcd(1, 1, "ser=%d  ", x);
}
