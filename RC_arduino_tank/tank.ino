int motor1_dir1 = 11;
int motor1_dir2 = 12;
int motor2_dir1 = 9;
int motor2_dir2 = 10;
int motor1 = 3;
int motor2 = 5;

int led;
int ledPin = 7;

int dir1;
int dir2;

int val1;
int val2;

int x1;
int x2;

int joy2 = A0;
int joy1 = A1;

int upper_bound = 520;
int lower_bound = 480;
int high_bound = 800;
int low_bound = 200;

int speed_limit = 100;
int low_speed = 150;
int high_speed = 255;

void setup()
{
  pinMode(motor1_dir1, OUTPUT);
  pinMode(motor1_dir2, OUTPUT);
  pinMode(motor2_dir1, OUTPUT);
  pinMode(motor2_dir2, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available() == 0);  
  x1 = Serial.parseInt();
  x2 = Serial.parseInt();
  led =  Serial.parseInt();


  if (x1 >= upper_bound) {
    if (x1 >= high_bound) {
      val1 = map(x1,high_bound, 1023, low_speed, high_speed);
    } else {
      val1 = map(x1,upper_bound, 800, speed_limit,low_speed);  
    }
    
    dir1 = -1;
  }

  if (x1 <= lower_bound) {
    if (x1 <= low_bound) {
      val1 = map(x1, 0, low_bound, 255, low_speed);
    } else {
      val1 = map(x1, low_bound, lower_bound,low_speed, speed_limit);  
    }    
    dir1 = 1;     
  }

  if (x2 >= upper_bound) {
    if (x2 >= high_bound) {
      val2 = map(x2,high_bound, 1023, low_speed, high_speed);
    } else {
      val2 = map(x2,upper_bound, 800, speed_limit,low_speed);  
    }    
    dir2 = -1;
  }

  if (x2 <= lower_bound) {
    if (x2 <= low_bound) {
      val2 = map(x2, 0, low_bound, 255, low_speed);
    } else {
      val2 = map(x2, low_bound, lower_bound,low_speed, speed_limit);  
    }    
    dir2 = 1;     
  }

  if((x1 < upper_bound) && (x1 > lower_bound)) {
    val1 = 0;
    dir1 = 0;
  }

  if((x2 < upper_bound) && (x2 > lower_bound)) {
    val2 = 0;
    dir2 = 0; 
  }
  
  digitalWrite(ledPin, led);
  
  analogWrite(motor1, val1);
  analogWrite(motor2, val2);
  
  if((dir1 == 1) && (dir2 == 1)) {
    digitalWrite(motor1_dir1, HIGH);
    digitalWrite(motor1_dir2, LOW);    
    digitalWrite(motor2_dir1, HIGH);
    digitalWrite(motor2_dir2, LOW);    
  }
  if((dir1 == -1) && (dir2 == 1)) {
    digitalWrite(motor1_dir1, HIGH);
    digitalWrite(motor1_dir2, LOW);    
    digitalWrite(motor2_dir1, LOW);
    digitalWrite(motor2_dir2, HIGH);     
  }

  if((dir1 == 1) && (dir2 == -1)) {
    digitalWrite(motor1_dir1, 0);
    digitalWrite(motor1_dir2, 1);     
    digitalWrite(motor2_dir1, 1);
    digitalWrite(motor2_dir2, 0);     
      }
  
  if((dir1 == -1) && (dir2 == -1)) {
    digitalWrite(motor1_dir1, 0);
    digitalWrite(motor1_dir2, 1);    
    digitalWrite(motor2_dir1, 0);
    digitalWrite(motor2_dir2, 1);    
  }
  
  if((dir1 == 0) && (dir2 == 1)) {
    digitalWrite(motor1_dir1, 1);
    digitalWrite(motor1_dir2, 0);    
    digitalWrite(motor2_dir1, 0);
    digitalWrite(motor2_dir2, 0);   
  }
  
  if((dir1 == 0) && (dir2 == -1)) {
    digitalWrite(motor1_dir1, 0);
    digitalWrite(motor1_dir2, 1);    
    digitalWrite(motor2_dir1, 0);
    digitalWrite(motor2_dir2, 0);   
  }
  if((dir1 == 1) && (dir2 == 0)) {
    digitalWrite(motor1_dir1, 0);
    digitalWrite(motor1_dir2, 0);   
    digitalWrite(motor2_dir1, 1);
    digitalWrite(motor2_dir2, 0); 
  }
  if((dir1 == -1) && (dir2 == 0)) {
    digitalWrite(motor1_dir1, 0);
    digitalWrite(motor1_dir2, 0); 
    digitalWrite(motor2_dir1, 0);
    digitalWrite(motor2_dir2, 1);   
  }
  
    if((dir1 == 0) && (dir2 == 0)) {
    digitalWrite(motor1_dir1, 0);
    digitalWrite(motor1_dir2, 0); 
    digitalWrite(motor2_dir1, 0);
    digitalWrite(motor2_dir2, 0); 
  }
  
 
  delay(50);
}
