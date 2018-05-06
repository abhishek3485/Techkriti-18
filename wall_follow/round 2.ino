#include <AFMotor.h>

// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
AF_DCMotor motorL(1, MOTOR12_64KHZ); 
AF_DCMotor motorR(2, MOTOR12_64KHZ);

#define SONAR_NUM 3      // Number of sensors.
#define MAX_DISTANCE 900 // Maximum distance (in cm) to ping.

int s1, s2, s3, s4, s5;

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(23, 22, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(27, 26, MAX_DISTANCE), 
  NewPing(25, 24, MAX_DISTANCE)
};

//int Wleft();
//int Wright();

#define SP 13
int error = 0;
int k = 0;
void setup() {
  
//  motorL.setSpeed();
//  motorR.setSpeed();
  Serial.begin(9600);
   pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(A14, INPUT);                   
}

void loop() { 
   
    s1 = analogRead(A10);
    s2 = analogRead(A11);
    s3 = analogRead(A12);
    s4 = analogRead(A13);
    s5 = analogRead(A14);
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through each sensor and display results.
     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    Serial.print(i);
    Serial.print("=");
    Serial.print(sonar[i].ping_cm());
    Serial.print("cm ");}
    Serial.println();
    
    while(((sonar[2].ping_cm())<70)&&(sonar[2].ping_cm())>0){
      Wright();
    }
   while((sonar[2].ping_cm()>70)){
    Wleft();
   }
     
 
}
int Wleft(){
  if(((sonar[1].ping_cm())<10)&&((sonar[1].ping_cm())>0)){
    
      motorL.setSpeed(98);
      motorR.setSpeed(98);
      motorL.run(FORWARD);
      motorR.run(BACKWARD);
      delay(900);
    
    
  }
  else if(((sonar[0].ping_cm())<10)&&((sonar[1].ping_cm())>0)){
       motorL.setSpeed(98);
      motorR.setSpeed(98);
      motorL.run(FORWARD);
      motorR.run(BACKWARD);
    
  }
//  else if(((sonar[2].ping_cm())<10)&&((sonar[2].ping_cm())>0)){
//      
//       motorL.setSpeed(240);
//     motorR.setSpeed(240);
//      motorL.run(BACKWARD);
//      motorR.run(FORWARD);
   
  }
  else{
      error = (sonar[2].ping_cm()-SP);
      if(error>0){
      motorL.setSpeed(240 + error);
      motorR.setSpeed(230);}
      else{
         motorL.setSpeed(230);
         motorR.setSpeed(240 + error);
      }
      motorL.setSpeed(60);
      motorR.setSpeed(98);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
      if((s1>550)&&(s2>550)&&(s3>550)&&(s4>550)&&(s5>550)){
        loop();
       
      }
  }
  return 0;
}
  int Wright(){
  if(((sonar[1].ping_cm())<10)&&((sonar[1].ping_cm())>0)){
    
      motorL.setSpeed(240);
      motorR.setSpeed(240);
      motorL.run(BACKWARD);
      motorR.run(FORWARD);
      delay(900);
    
    
  }
//  else if(((sonar[0].ping_cm())<10)&&((sonar[1].ping_cm())>0)){
//       motorL.setSpeed(240);
//      motorR.setSpeed(240);
//      motorL.run(FORWARD);
//      motorR.run(BACKWARD);
//    
//  }
  else if(((sonar[2].ping_cm())<10)&&((sonar[2].ping_cm())>0)){
      
       motorL.setSpeed(240);
      motorR.setSpeed(240);
      motorL.run(BACKWARD);
      motorR.run(FORWARD);
   
  }
  else{
//      error = (sonar[2].ping_cm()-SP);
//      if(error>0){
//      motorL.setSpeed(240 + error);
//      motorR.setSpeed(230);}
//      else{
//         motorL.setSpeed(230);
//         motorR.setSpeed(240 + error);
//      }
      motorL.setSpeed(250);
      motorR.setSpeed(200);
      motorL.run(FORWARD);
      motorR.run(FORWARD);
  }
//  if((sonar[0].ping_cm()<70)&&(sonar[0].ping_cm())>0){                  //"70" check on the spot!!!!!!
//    Wleft();
//    
//  }
  return 0;
  }
 

  
 
 


