#include "BatteryList.h"

class Application {
public:
    Application() { }
    int run() {
        // return something

        BatteryList list;

        int32_t command=-1;

        while(command!=5){
            std::cout
            <<"What do you want to do?"<<std::endl
            <<"1: Add a new battery"<<std::endl
            <<"2: Delete a battery"<<std::endl
            <<"3: Sort batteries"<<std::endl
            <<"4: Print batteries"<<std::endl
            <<"5: Exit"<<std::endl
            <<"Command: ";

            std::cin>>command;
            std::cout<<std::endl;

            if(command==1){
                list.addBattery();
            }

            else if(command==2){
                list.deleteBattery();
            }

            else if(command==3){
                list.sortBattery();
            }

            else if(command==4){
                list.printBattery();
            }

            else if(command==5){
                std::cout<<"Program is terminated.";
            }

            else{
                std::cerr<<"Please enter a valid value."<<std::endl;
            }

            std::cout<<std::endl;
        }

        return 0;
    }
};

int main()
{
    Application tApplication;
    return tApplication.run();
}
