#ifndef COOL_CAR_LIB_H_
#define COOL_CAR_LIB_H_

#include <Arduino.h>

/* ###############  CoolCarBasic ############### */

class CoolCarBasic  // Class Declaration
{
    public: 
        CoolCarBasic(uint8_t);  // Constructor
    
        uint8_t getMaxPassengers();
        uint16_t getSpeed();
        void setSpeed(uint16_t);
        void hoot();
                 
    private:
        uint8_t maxPassengers;
        uint16_t speed;
};

/* #################  CoolCar ################ */

enum cc_ac_level{   
    CC_AC_OFF, CC_AC_LOW, CC_AC_MEDIUM, CC_AC_HIGH, CC_AC_MAX
}; 

class CoolCar
{
    public: 
        CoolCar(char *br, size_t brSize,  uint8_t mP, uint16_t mSp, float len = 4.2);
        
        void init();
        char* getBrand();
        uint8_t getMaxPassengers();
        uint16_t getMaxSpeed();
        float getLengthInMeters();
        void hoot();
        bool accelerate(uint16_t accVal);
        void brake(uint16_t brakeVal);
        uint16_t getCurrentSpeed();
        void setAirConLevel(cc_ac_level acLevel);
        cc_ac_level getAirConLevel();
            
    private:
        uint8_t maxPassengers;
        uint16_t maxSpeed;
        float length; 
        int16_t currentSpeed;
        cc_ac_level airConLevel;
        char brand[];

        int16_t calculateNewSpeed(int16_t value);
};

#endif


