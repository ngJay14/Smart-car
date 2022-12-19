
#define motorA1 4  
#define motorA2 12 
#define motorAspeed 5 
#define motorB1 0
#define motorB2 2
#define motorBspeed 32      
const int L_S1 = 33; // cb dò line phải 1
const int L_S2 = 35; // cb dò line phải 2
const int S_S = 39; // cb dò line giữa
const int R_S1 = 34; //cb dò line trái 1
const int R_S2 = 14; //cb dò line trái 2
void setup() {
  pinMode(L_S1, INPUT);
  pinMode(L_S2, INPUT); 
  pinMode(R_S1, INPUT);
  pinMode(R_S2, INPUT);
  pinMode(S_S, INPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorAspeed, OUTPUT);
  pinMode(motorBspeed, OUTPUT);

}


void loop()
{

  if ((digitalRead(L_S1) == 1) && (digitalRead(S_S) == 0) && (digitalRead(R_S1) == 1)) {
    forword(); // đi tiến
  }
  if ((digitalRead(L_S2) == 1) && (digitalRead(S_S) == 0) && (digitalRead(R_S2) == 1)) {
    forword(); // đi tiến
  }

  if ((digitalRead(L_S1) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S1) == 1)) {
    turnLeft(); 
  }
  if ((digitalRead(L_S2) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S2) == 1)) {
    turnLeft(); 
  }
  if ((digitalRead(L_S1) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S1) == 1)) {
    turnLeft(); 
  }
  if ((digitalRead(L_S2) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S2) == 1)) {
    turnLeft(); 
  }


  if ((digitalRead(L_S1) == 1) && (digitalRead(S_S) == 0) && (digitalRead(R_S1) == 0)) {
    turnRight(); // rẻ phải
  }
  if ((digitalRead(L_S2) == 1) && (digitalRead(S_S) == 0) && (digitalRead(R_S2) == 0)) {
    turnRight(); // rẻ phải
  }
  if ((digitalRead(L_S1) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S1) == 0)) {
    turnRight(); // rẻ phải
  }
   if ((digitalRead(L_S2) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S2) == 0)) {
    turnRight(); // rẻ phải
  }

  if ((digitalRead(L_S1) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S1) == 0)&&(digitalRead(L_S2) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S2) == 0)) {
    xoayphai(); 
  }
   if ((digitalRead(L_S1) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S1) == 1)&&(digitalRead(L_S2) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S2) == 1)) {
    lui(); // đi lùi
  }
  if ((digitalRead(L_S1) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S1) == 1)&&(digitalRead(L_S2) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S2) == 0)) {
    turnRight(); // rẻ phải
  }
   if ((digitalRead(L_S1) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S1) == 1)&&(digitalRead(L_S2) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S2) == 1)) {
   turnLeft(); // rẻ trái
  }
}



  
void forword() { 

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite (motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorAspeed, 180); 
  analogWrite(motorBspeed, 200);
}


void turnLeft() {

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite (motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorAspeed, 180); 
  analogWrite(motorBspeed, 200);
}

void turnRight() {

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite (motorB1, LOW);
  digitalWrite(motorB2, LOW);
  analogWrite(motorAspeed, 180);
  analogWrite(motorBspeed, 200);
}

void Stop() {

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite (motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
void lui() { 

  digitalWrite (motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite (motorB1, LOW);
  digitalWrite(motorB2, HIGH);
   analogWrite(motorAspeed, 100); 
   analogWrite(motorBspeed, 110);
}
void xoaytrai() { 

  digitalWrite (motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite (motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorAspeed, 160); 
  analogWrite(motorBspeed, 180);
}
void xoayphai() { 

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite (motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorAspeed, 160); 
  analogWrite(motorBspeed, 180);
}

