#include <Servo.h>
Servo servo_pin_11;
Servo servo_pin_10;
int irSensor = 0;
int light;
void setup()
{
  Serial.begin(9600);
  servo_pin_11.attach(11);
  servo_pin_10.attach(10);
  pinMode(0,INPUT);
  delay(1000);  
}
void loop()
{
  light = analogRead(A0);
  Serial.println("Analog Value");
  Serial.println(light);
  Serial.println("IR Sensor Value");
  Serial.println(digitalRead(irSensor));
  if ( ( light ) <= ( 250 )  ) {
    tone(3, 500);
    servo_pin_11.write(45);
    servo_pin_10.write(135);
  }
  else
  {
    delay(150);
    tone(3, 400);
    servo_pin_11.write(90);
    servo_pin_10.write(135);
  }
  if(digitalRead(irSensor) == 0){
    servo_pin_11.write(90);
    servo_pin_10.write(135);
    if(digitalRead(irSensor) == 1) {
      tone(3, 500);
      servo_pin_11.write(135);
      servo_pin_10.write(45);
    }
  }
}
