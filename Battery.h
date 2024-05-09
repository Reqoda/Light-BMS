#ifndef H_Battery
#define H_Battery

#include<cstdlib>
#include<iostream>
#include<time.h>
#include<iomanip>

class Battery{
    private:
        int32_t id=0;
        int32_t measurePin=0, balancePin=1;
        int32_t voltage;

    public:

        Battery(){
            voltage=((rand()%700)+3500);
        }

        Battery(int32_t id, int32_t mPin, int32_t bPin){
            setBattery(id, mPin, bPin);
        }

        ~Battery(){}

        void setBattery(int32_t id, int32_t mPin, int32_t bPin){
            this->id = id;
            measurePin = mPin;
            balancePin = bPin;
            voltage=((rand()%700)+3500);
        }

        void printBattery(){
            std::cout<<"Battery["<<id<<"]: Voltage = "<<voltage/1000
            <<"."<<std::setfill('0')<<std::setw(3)<<voltage%1000<<", Measure Pin = "
            <<measurePin<<", Balance Pin = "
            <<balancePin<<std::endl;
        }

        int32_t getMeasurePin(){
            return measurePin;
        }
        
        int32_t getBalancePin(){
            return balancePin;
        }
        
        int32_t getId(){
            return id;
        }

        int32_t getVoltage(){
            return voltage;
        }

        void operator=(const Battery& btry) 
        { 
            id = btry.id;
            voltage = btry.voltage;
            measurePin = btry.measurePin;
            balancePin = btry.balancePin;
        }
};

#endif