#include <Servo.h>

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo sMotor;

int i;

void setup() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.begin(9600);

  sMotor.attach(13);
}

void loop() {

  if(Serial.available()){

    char data = Serial.read();
    Serial.print(data);
    
    if(data == 'a'){
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(BACKWARD);
      motor1.setSpeed(255);
      motor2.setSpeed(255);
      motor3.setSpeed(255);
      motor4.setSpeed(255);
    }
    if(data == 'b'){
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor2.setSpeed(255);
      motor3.setSpeed(255);

    }
    if(data == 'c'){
      motor1.run(FORWARD);
      motor4.run(BACKWARD);
      motor1.setSpeed(255);
      motor4.setSpeed(255);
    }
    if(data == 'd'){
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor2.setSpeed(255);
      motor3.setSpeed(255);
    }
    if(data == 'e'){
      motor1.run(BACKWARD);
      motor4.run(FORWARD);
      motor1.setSpeed(255);
      motor4.setSpeed(255);
    }
    if(data == 'f'){
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(FORWARD);
      motor1.setSpeed(255);
      motor2.setSpeed(255);
      motor3.setSpeed(255);
      motor4.setSpeed(255);
    }
    if(data == 'g'){
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }

    if(data == 't'){
      for(i = 0; i < 179; i++){
        sMotor.write(i);
        data = Serial.read();
        if(data == 'z'){
          break;
        }
        delay(500);
      }
    }

    if(data == 'u'){
      for(i = 180; i>0; i--){
        sMotor.write(i);
        data = Serial.read();
        if(data == 'z'){
          break;
        }
        delay(500);
      }
    }

    if(data == 'x'){
      sMotor.write(90);
    }
    
  }
  
}
