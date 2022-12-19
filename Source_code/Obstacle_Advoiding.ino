
#define ENA   5              
#define ENB   32                
#define IN_1  4                
#define IN_2  12                    
#define IN_3  0                
#define IN_4  2                   

#include <Servo.h>
Servo myservo; 



const int trig = 23;     // chân trig của SRF-05.
const int echo = 22;     // chân echo của SRF-05.
int dongcoservo=18;      // chân Orange của Servo.

int gioihan = 25;
int i;
int x=0;
unsigned long thoigian; // biến đo thời gian
int khoangcach;           // biến lưu khoảng cách
int khoangcachtrai,khoangcachphai;

void dokhoangcach();
void dithang(int duongdi);
void disangtrai();
void disangphai();
void dilui();
void resetdongco();
void quaycbsangphai();
void quaycbsangtrai();
void setup() {
  // put your setup code here, to run once:
    myservo.attach(18);  
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
    
    pinMode(IN_1,OUTPUT); 
    pinMode(IN_2,OUTPUT); 
    pinMode(IN_3,OUTPUT); 
    pinMode(IN_4,OUTPUT); 
    pinMode(ENA,OUTPUT); 
    pinMode(ENB,OUTPUT); 
    digitalWrite(IN_1,LOW);
    digitalWrite(IN_2,LOW);
    digitalWrite(IN_3,LOW);
    digitalWrite(IN_4,LOW);
   // Serial.begin(9600);
    myservo.write(90);    
    delay(500);
   
    
    
}

void loop() 
{   
    khoangcach=0;
    dokhoangcach();
    if(khoangcach>gioihan||khoangcach==0) 
    {
      dokhoangcach();
       if(khoangcach>gioihan||khoangcach==0) 
        {
          dithang();   
        }   
    }
    else
    {
      
      resetdongco();
      quaycbsangtrai();
      
      khoangcachtrai=khoangcach;
     
      quaycbsangphai();
      khoangcachphai=khoangcach;
      if((khoangcachphai<25&&khoangcachtrai<25)||khoangcachphai==khoangcachtrai){
        dilui();
        delay(500);
      }
      else
      {
        if(khoangcachphai>khoangcachtrai) 
        {
          dilui();
          delay(500);
          disangphai();
          delay(300);
        }
        if(khoangcachphai<khoangcachtrai) 
        {
          dilui();
          delay(500);
          disangtrai();
          delay(300);
        }
      }
    }
  //Serial.println(khoangcach);


}
void dithang()
{ 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, 180);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, 180);
   
}

void disangtrai()
{
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, 180);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, 180);
  }
    

void disangphai()
{
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, 180);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, 180);
}

void dilui()
{
     digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, 180);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, 180);
  }


void resetdongco()
{
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, 0);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, 0);
}
/******** chương trình đo khoảng cách SRF04 ***************/
void dokhoangcach()
{
/* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(10);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    thoigian = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    khoangcach = int(thoigian/2/29.412);
    

}


void quaycbsangtrai()
{
    myservo.write(180);              
    delay(1000);
    dokhoangcach();
    myservo.write(90);              
}
void quaycbsangphai(){

    myservo.write(0);              
    delay(1000);
    dokhoangcach();
    myservo.write(90);              
}
void resetservo()
{
   myservo.write(90);
}



