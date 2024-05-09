#ifndef H_BatteryList
#define H_BatteryList

#include "Battery.h"
#include<vector>
#define MAX_PIN 40
#define MAX_BATTERY 20
#define MIN 0

class BatteryList{
    private:
        std::vector<std::vector<int32_t>> pinList;
        std::vector<Battery> batteryList;

        int32_t idCounter=1;
    public:
        BatteryList(){
            for(int32_t i = 0; i<=MAX_PIN;i++){
                pinList.push_back({-1,-1});
                //for pinList[i][j], i holds pinId, j=0 holds batteryId,
                //j=1 holds is it balance("0") pin or measure("1") pin
            }
            srand(time(0));
        }
        BatteryList(Battery newBtry){
            for(int32_t i = 0; i<=MAX_PIN;i++){
                pinList.push_back({i,-1,-1});
            }
            batteryList.push_back(newBtry);
            pinList[newBtry.getBalancePin()]={newBtry.getId(),0};
            pinList[newBtry.getMeasurePin()]={newBtry.getId(),1};
            srand(time(0));
        }

        ~BatteryList(){}

        bool addBattery(){
            if(batteryList.size()==MAX_BATTERY){
                std::cerr<<"There is no empty slot to add new battery"<<std::endl;
                return false;
            }

            else{
                int32_t mPin,bPin;

                std::cout<<"Enter a battery voltage measure pin: ";
                std::cin>>mPin;

                if(mPin > MAX_PIN || mPin < MIN){
                    std::cerr<<"Measure pin should be between 0-40."<<std::endl;
                    return false;
                }

                else{
                    std::cout<<"Enter a battery balance pin: ";
                    std::cin>>bPin;
                }

                if(bPin > MAX_PIN || bPin < MIN){
                    std::cerr<<"Balance pin should be between 0-40."<<std::endl;
                    return false;
                }

                else if(mPin==bPin){
                    std::cerr<<"Balance pin and measure pin cannot be same."<<std::endl;
                    return false;
                }

                else if(pinList[mPin][0]!=-1 || pinList[bPin][0]!=-1){

                    std::cerr<<std::endl;

                    if(pinList[mPin][1]==0){
                        std::cerr<<"Measure pin of the battery is used by Battery["
                        <<pinList[mPin][0]<<"] as balance pin."<<std::endl;
                    }

                    else if(pinList[mPin][1]==1){
                        std::cerr<<"Measure pin of the battery is used by Battery["
                        <<pinList[mPin][0]<<"] as measure pin."<<std::endl;
                    }

                    if(pinList[bPin][1]==0){
                        std::cerr<<"Balance pin of the battery is used by Battery["
                        <<pinList[bPin][0]<<"] as balance pin."<<std::endl;
                    }

                    else if(pinList[bPin][1]==1){
                        std::cerr<<"Balance pin of the battery is used by Battery["
                        <<pinList[bPin][0]<<"] as measure pin."<<std::endl;
                    }

                    std::cerr<<"Battery is not added"<<std::endl;
                    
                    return false;
                }

                else{
                    Battery newBattery(idCounter++,mPin,bPin);
                    batteryList.push_back(newBattery);

                    pinList[mPin][0]=newBattery.getId();
                    pinList[mPin][1]=1;
                    pinList[bPin][0]=newBattery.getId();
                    pinList[bPin][1]=0;

                    std::cout<<"Battery is added with "<<newBattery.getVoltage()/1000
                    <<"."<<std::setfill('0')<<std::setw(3)<<newBattery.getVoltage()%1000<<" Volt."<<std::endl;
                }
            }
            return true;
        }

        bool deleteBattery(){
            if(batteryList.size()==MIN){
                std::cerr<<"There is no battery to delete."<<std::endl;
            }

            else{
                int32_t idToDelete;
                std::cout<<"Battery ID that will deleted: ";
                std::cin>>idToDelete;



                for(int32_t i=0;i<batteryList.size();i++){
                    if(batteryList[i].getId()==idToDelete){
                        
                        pinList[batteryList[i].getMeasurePin()][0]=-1;
                        pinList[batteryList[i].getMeasurePin()][1]=-1;
                        
                        pinList[batteryList[i].getBalancePin()][0]=-1;
                        pinList[batteryList[i].getBalancePin()][1]=-1;

                        batteryList.erase(std::next(batteryList.begin(),i));

                        std::cout<<"Battery["<<idToDelete<<"] is deleted."
                        <<std::endl;

                        return true;
                    }
                }

                std::cerr<<"Battery["<<idToDelete<<"] is not found."
                <<std::endl;
            }

            return false;
        }

        void sortBattery(){
            if(batteryList.size()==MIN){
                std::cerr<<"There is no battery to sort."<<std::endl;
            }

            else{
                int32_t minIndex;
                for(int32_t i=0;i<batteryList.size();i++){
                    minIndex=i;
                    for(int32_t j=i+1;j<batteryList.size();j++){
                        if(batteryList[j].getVoltage()<batteryList[minIndex].getVoltage()){
                            minIndex=j;
                        }
                    }

                    Battery temp = batteryList[i];
                    batteryList[i] = batteryList[minIndex];
                    batteryList[minIndex] = temp;
                }

                std::cout<<"Batteries are sorted"<<std::endl;
            }
        }

        void printBattery(){
            if(batteryList.size()==MIN){
                std::cerr<<"There is no battery to print."<<std::endl;
            }

            else{
                for(int32_t i=0;i<batteryList.size();i++){
                    batteryList[i].printBattery();
                }
            }
        }
};

#endif