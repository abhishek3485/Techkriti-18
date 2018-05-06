#include <AFMotor.h>

int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;

#define thres 550
#define Setpoint 550

AF_DCMotor motorL(1, MOTOR12_64KHZ); 
AF_DCMotor motorR(2, MOTOR12_64KHZ);

void setup() {

   
Serial.begin(9600);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(A14, INPUT);
  pinMode(A15, INPUT);
  pinMode(32, OUTPUT);
  motorL.setSpeed(100);
  motorR.setSpeed(105);
  motorL.run(FORWARD);
  motorR.run(FORWARD);
  delay(700);
  
}

void loop() {
   s1 = analogRead(A10);
   s2 = analogRead(A11);
   s3 = analogRead(A12);
   s4 = analogRead(A13);
   s5 = analogRead(A14);
    
    Serial.println("\ns1,s2,s3,s4,s5:  ");
    Serial.print(s1 );
    Serial.print(" ");
    Serial.print(s2 );
    Serial.print(" ");
    Serial.print(s3 );
    Serial.print(" ");
    Serial.print(s4) ;
    Serial.print(" ");
    Serial.print(s5 );
 

    if((s1<thres)&&(s2>thres)&&(s3>thres)&&(s4>thres)&&(s5<thres)){                     //Forward
      motorL.setSpeed(100);
      motorR.setSpeed(100); 
      motorL.run(FORWARD);
      motorR.run(FORWARD);

    }
    else if((s1<thres)&&(s2>thres)&&(s3>thres)&&(s4<thres)&&(s5<thres)){     // soft right
      motorL.setSpeed(100);
      motorR.setSpeed(60);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
    }
     else if((s1>thres)&&(s2>thres)&&(s3<thres)&&(s4<thres)&&(s5<thres)){              //soft right
      motorL.setSpeed(100);
      motorR.setSpeed(60);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
     }

    else if((s1>thres)&&(s2<thres)&&(s3<thres)&&(s4<thres)&&(s5<thres)){                  //soft right
      motorL.setSpeed(100);
      motorR.setSpeed(60);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
    }
    else if((s1<thres)&&(s2<thres)&&(s3>thres)&&(s4>thres)&&(s5<thres)){                  //soft left
      motorL.setSpeed(60);
      motorR.setSpeed(100);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
    }
    else if((s1<thres)&&(s2<thres)&&(s3<thres)&&(s4>thres)&&(s5>thres)){                //soft left
      motorL.setSpeed(60);
      motorR.setSpeed(100);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
    }
     else if((s1<=thres)&&(s2<=thres)&&(s3<=thres)&&(s4<=thres)&&(s5>=thres)){                  //soft left
      motorL.setSpeed(60);
      motorR.setSpeed(100);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
    }

    else if((s1>thres)&&(s2>thres)&&(s3>thres)&&(s4>thres)&&(s5<thres)){                     //Turn right
      motorL.setSpeed(100);
      motorR.setSpeed(100);                          
      motorL.run(FORWARD);
      motorR.run(BACKWARD);
    }

    
    
    else if((s1<thres)&&(s2>thres)&&(s3>thres)&&(s4>thres)&&(s5>thres)){ 
                                                                                                 //turn left
      motorL.setSpeed(0);
      motorR.setSpeed(100);                          
      motorL.run(FORWARD);
      motorR.run(FORWARD);
      delay(700);
    }
    else if((s1<thres)&&(s2<thres)&&(s3<thres)&&(s4<thres)&&(s5<thres)){                     //U-turn
     
      motorL.setSpeed(99);
      motorR.setSpeed(99);                            
      motorL.run(FORWARD);
      motorR.run(BACKWARD);
          }
    else if((s1>=thres)&&(s2>=thres)&&(s3>=thres)&&(s4>=thres)&&(s5>=thres))                      //complete black right turn
    {
//      if(digitalRead(A15) == HIGH){
//      count++;
//      motorL.setSpeed(110);
//      motorR.setSpeed(110);
//      motorL.run(FORWARD);
//      motorR.run(FORWARD);
//      }
//      else{
      motorL.setSpeed(100);
      motorR.setSpeed(100);
      motorL.run(FORWARD);
      motorR.run(BACKWARD);
      }
//      delay(700);
//       if((s1>=thres)&&(s2>=thres)&&(s3>=thres)&&(s4>=thres)&&(s5>=thres)){
//        motorR.run(RELEASE);
//        motorL.run(RELEASE);
//        digitalWrite(32, HIGH);
//        delay(2000);
//        digitalWrite(32, LOW);
//        delay(2000);
       }
      
         
    
  
//    
//    if(count==2){
//      
//      motorL.run(RELEASE);
//     motorR.run(RELEASE);
//    }
     
