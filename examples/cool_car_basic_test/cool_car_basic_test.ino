#include <CoolCarLib.h>

CoolCarBasic myCar = CoolCarBasic(7); // 7 passengers is maximum

void setup() {
  Serial.begin(9600);
  
  byte passengerLimit = myCar.getMaxPassengers();
  unsigned int currentSpeed = myCar.getSpeed();
  
  Serial.print("Max. number of passengers: ");
  Serial.println(passengerLimit);
  
  Serial.print("CurrentSpeed [km/h]: ");
  Serial.println(currentSpeed);
  
  myCar.setSpeed(50);
  currentSpeed = myCar.getSpeed();
  Serial.print("CurrentSpeed [km/h]: ");
  Serial.println(currentSpeed);
  
  myCar.hoot();  
}

void loop() {}
