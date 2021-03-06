#ifndef MOVING_H
#define MOVING_H

#define TURN_DELAY 1500

class Moving 
{
public:
  Moving::Moving
  (
    int pin1,
    int pin2,
    int pin3,
    int pin4
  );

  void restore();
  void goFoward();
  void goBackward();
  void turnLeft();
  void turnRight();
  void moveLeft();
  void moveRight();
  
private:
  int relePin1;
  int relePin2;
  int relePin3;
  int relePin4;

  bool moving;
  bool turning;
};

Moving::Moving
(
  int pin1,
  int pin2,
  int pin3,
  int pin4
)
  : relePin1(pin1),
    relePin2(pin2),
    relePin3(pin3),
    relePin4(pin4)
{
  pinMode ( relePin1, OUTPUT );
  pinMode ( relePin2, OUTPUT );
  pinMode ( relePin3, OUTPUT );
  pinMode ( relePin4, OUTPUT );    
  delay(100);
}

void Moving::restore()
{
  digitalWrite( relePin1, LOW );
  digitalWrite( relePin2, LOW );
  digitalWrite( relePin3, HIGH );
  digitalWrite( relePin4, HIGH );
}

void Moving::turnLeft()
{
  restore();
  delay(20);
  digitalWrite( relePin3, HIGH );
  delay(TURN_DELAY);
  restore();
}

void Moving::turnRight()
{
  restore();
  delay(20);
  digitalWrite( relePin4, HIGH );
  delay(TURN_DELAY);
  restore();
}

void Moving::goFoward()
{
  restore();
  delay(20);
  digitalWrite( relePin1, LOW );
}

void Moving::goBackward()
{
  restore();
  delay(20);
  digitalWrite( relePin2, HIGH );
}

void Moving::moveLeft()
{
  restore();
  delay(20);
  digitalWrite( relePin3, HIGH );
}

void Moving::moveRight()
{
  restore();
  delay(20);
  digitalWrite( relePin4, HIGH );
}

#endif
