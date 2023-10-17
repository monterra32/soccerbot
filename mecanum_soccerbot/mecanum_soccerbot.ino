 struct Wheel{
  int IN_1;
  int IN_2 ;
  int ENPort;
}

wheels[4] = {
          {22, 23, 2},
          {24, 25, 3},
          {26, 27, 4},
          {28, 29, 5},
      };


void setup() {
  Serial.begin(9600);
// set up pins
  for (int i=0; i<4; i++){
    pinMode(wheels[i].IN_1, OUTPUT);
    pinMode(wheels[i].IN_2, OUTPUT);
    pinMode(wheels[i].ENPort, OUTPUT);
  }

}

void loop() {
  Serial.println("paper plates");

  drive (wheels[1], -149);
  // Rotate the Motor A clockwise
}


// speed should be -255~255.
void drive (Wheel wh, int speed){
  analogWrite(wh.ENPort, abs(speed));
  if (speed>0){
    digitalWrite(wh.IN_1, HIGH);
    digitalWrite(wh.IN_2, LOW);
  }
  else if (speed<0){
    digitalWrite(wh.IN_1, LOW);
    digitalWrite(wh.IN_2, HIGH);
  }


  
}
  
