#include <CoolCarLib.h>

char producer[] = {"Audi"};
CoolCar myCar(producer, sizeof(producer), 5, 180, 3.5); 
// Alternative: CoolCar myCar(producer, sizeof(producer), 5, 180); 

void setup() {
  Serial.begin(9600);
  myCar.init();
  Serial.println(myCar.getBrand()); 
  Serial.print("Max. number of passengers: ");
  Serial.println(myCar.getMaxPassengers());
  Serial.print("Max. Speed [km/h]: ");
  Serial.println(myCar.getMaxSpeed());
  Serial.print("Length [meters]: ");
  Serial.println(myCar.getLengthInMeters());
  myCar.hoot();
  Serial.print("Speed: ");
  Serial.println(myCar.getCurrentSpeed());

  if(!myCar.accelerate(50)){
    Serial.println("Speed Limit Warning!"); 
  }
  Serial.print("New Speed [km/h]: ");
  Serial.println(myCar.getCurrentSpeed());

  if(!myCar.accelerate(150)){
    Serial.println("Acceleration warning!!"); 
  }
  Serial.print("New Speed [km/h]: ");
  Serial.println(myCar.getCurrentSpeed());

  Serial.print("Air Conditioning Level: ");
  Serial.println(myCar.getAirConLevel());

  myCar.brake(60);
  Serial.print("New Speed [km/h]: ");
  Serial.println(myCar.getCurrentSpeed());

  myCar.setAirConLevel(CC_AC_MEDIUM);
  Serial.print("Air Con Level [num]: ");
  Serial.println(myCar.getAirConLevel());
  printAirConLevel();
}

void loop() {} 

void printAirConLevel(){
  cc_ac_level acLevel = myCar.getAirConLevel(); 
  Serial.print("Air Con Level [level]: ");
  switch(acLevel){
    case CC_AC_OFF:
      Serial.println("off");
      break;
    case CC_AC_LOW:
      Serial.println("low");
      break;
    case CC_AC_MEDIUM:
      Serial.println("medium");
      break;
    case CC_AC_HIGH:
      Serial.println("high");
      break;
    case CC_AC_MAX:
      Serial.println("maximum");
      break; 
    default:
      Serial.print("couldn't detect");
  }
}
