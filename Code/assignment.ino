int motorPwm = 0;
int pot = 0;
const int d1 = 11;
const int d2 = 10;
const int d3 = 9;
const int d4 = 6;
const int m1switch1 = 2;
const int m1switch2 = 4;
const int m2switch1 = 12;
const int m2switch2 = 13;
const int m1 = 5;
const int m2 = 3;
int sum = 0;
  
void setup()
{
  //potentiometer
  pinMode(A0,INPUT); 
  
  // setup motors
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m1switch1,OUTPUT);
  pinMode(m1switch2,OUTPUT);
  pinMode(m2switch1,OUTPUT);
  pinMode(m2switch2,OUTPUT);
  
  //setup dipswitches
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  pot = analogRead(A0);
  motorPwm = map(pot,1023,0,1,255); //receive val from potentiometer and convert to a usable number

  Serial.println(pot);
  int dip1 = digitalRead(d1);
  int dip2 = digitalRead(d2);
  int dip3 = digitalRead(d3);
  int dip4 = digitalRead(d4);
  
  sum = dip1 + dip2 + dip3 + dip4;
  
  if (sum==3) {
    if (dip1==0 && sum==3) { //forward
      digitalWrite(m1switch1,HIGH);
      digitalWrite(m1switch2,LOW);
      digitalWrite(m2switch1,HIGH);
      digitalWrite(m2switch2,LOW);
  	}
  	else if (dip2==0 && sum==3) { // backward
      digitalWrite(m1switch1,LOW);
      digitalWrite(m1switch2,HIGH);
      digitalWrite(m2switch1,LOW);
      digitalWrite(m2switch2,HIGH);
  	}
  	else if (dip3==0 && sum==3) { //turn left
      digitalWrite(m1switch1,LOW);
      digitalWrite(m1switch2,HIGH);
      digitalWrite(m2switch1,HIGH);
      digitalWrite(m2switch2,LOW);
 	}
  	else if (dip4==0 && sum==3) { //turn right
      digitalWrite(m1switch1,HIGH);
      digitalWrite(m1switch2,LOW);
      digitalWrite(m2switch1,LOW);
      digitalWrite(m2switch2,HIGH);
  	}
  }
  else {
  	  digitalWrite(m1switch1,LOW); //engine off     
      digitalWrite(m1switch2,LOW);
      digitalWrite(m2switch1,LOW);
      digitalWrite(m2switch2,LOW); 
  }
  
  analogWrite(m1,motorPwm);
  analogWrite(m2,motorPwm);
  
  delay(200);
} 