//define pins
const int PIA = 11;
const int PIB = 12;
const int AIA = 3;  //moter A channel a
const int AIB = 4;  //moter A channel b
const int BIA = 5;  //moter B channel a
const int BIB = 6;  //moter B channel b
const int RCPin2 = 2; //arduino port 2
const int RCPin7 = 7; //arduino port 7
const int RCPin10 = 10; //arduino port 10

float throttleX;
float throttleY;
float shooterThrottle;
void setup() {
  Serial.begin(9600);
  pinMode(RCPin10, INPUT);
  pinMode(RCPin2, INPUT);
  pinMode(RCPin7, INPUT);
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  pinMode(PIA, OUTPUT);
  pinMode(PIB, OUTPUT);
}

void loop() {
  throttleX = pulseIn(RCPin2, HIGH);
  throttleY = pulseIn(RCPin7, HIGH);
  shooterThrottle=pulseIn(RCPin10, HIGH);

  // if value is close to neutral, set to neutral
  if (throttleX > 1450 && throttleX < 1550){
    throttleX = 1500;
  }
  if (throttleY > 1450 && throttleY < 1550){
    throttleY = 1500;
  }
  if (shooterThrottle > 1450 && shooterThrottle < 1550){
    shooterThrottle = 1500;
  }
  // convert to speed 
  float speedA = 2.0*((((throttleY-1000.0)+(throttleX-1500.0))/((200.0/51.0)))-(127.5));
  float speedB = 2.0*((((throttleY-1000.0)-(throttleX-1500.0))/(200.0/51.0))-(127.5));
  // 

  if (shooterThrottle>1500){
    analogWrite(PIA, 255);
    analogWrite(PIB, 0);
  
  }
  else{
    analogWrite(PIA, 0);
    analogWrite(PIB, 0);
  }
  if (speedA<0 && speedB<0){
    analogWrite(AIA, abs(speedA));
    analogWrite(AIB, 0);
    analogWrite(BIA, abs(speedB));
    analogWrite(BIB, 0);
  }
  else if (speedA>0 && speedB>0){

    analogWrite(AIA, 0);
    analogWrite(AIB, abs(speedA));
    analogWrite(BIA, 0);
    analogWrite(BIB, abs(speedB));
  }
  else if (speedA<0 && speedB>0){
    analogWrite(AIA, abs(speedA));
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, abs(speedB));
  }
  else if (speedA>0 && speedB<0){

    analogWrite(AIA, 0);
    analogWrite(AIB, abs(speedA));
    analogWrite(BIA, abs(speedB));
    analogWrite(BIB, 0);
  }
  else{
    analogWrite(AIA, 0);
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, 0);
  }

  
  Serial.println(String(throttleX)+","+String(throttleY)+", "+String(abs(speedA))+", "+String(abs(speedB))+", "+String(shooterThrottle));
}
  // Serial.println("throttleY" + throttleY);
  /*
  forward();
  delay(10000);
  backward();
  delay(10000);
  */


/*void backward(speed) {
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);

}


void forward(speed) {
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}
*/