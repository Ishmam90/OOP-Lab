#include<iostream>
using namespace std;

class IVehicle{
    public:
        virtual void start()=0;
        virtual void stop()=0;
};

class IGPSVehicle{
    public:
        virtual void enableGPS(string ssid)=0;
        virtual void disableGPS()=0;
};

class Vehicle : public IVehicle{
    protected:
        string vehicleName;

    public:
        Vehicle(string vehicleName){
            this->vehicleName=vehicleName;
        }

        void start() override{
            cout<<"Vehicle started"<<endl;
        }

        void stop() override{
            cout<<"Vehicle stopped"<<endl;
        }

        void showVehicle() const{
            cout<<"Vehicle name: "<<vehicleName<<endl;
        }
};

class ConnectedVehicle : public IVehicle, public IGPSVehicle{
    protected:
        string vehicleName;
        int fuelLevel;

    public:
        ConnectedVehicle(){
            vehicleName="None";
            fuelLevel=0;
        }

        ConnectedVehicle(string vehicleName, int fuelLevel){
            this->vehicleName=vehicleName;
            if(fuelLevel>=0)    this->fuelLevel=fuelLevel;
        }

        void start() override{
            cout<<"Vehicle started"<<endl;
        }

        void stop() override{
            cout<<"Vehicle stopped"<<endl;
        }

        void showVehicle() const{
            cout<<"Vehicle name: "<<vehicleName<<endl;
        }

        void refuel(int amount){
            if(amount>0)    fuelLevel+=amount;
        }

        void checkFuel() const{
            cout<<fuelLevel<<endl;
        }

        void enableGPS(string ssid) override{
            cout<<"GPS enabled for "<<ssid<<endl;
        }

        void disableGPS() override{
            cout<<"GPS disabled"<<endl;
        }
};

class AutonomousCar : public ConnectedVehicle{
    protected:
        string carID;

    public:
        AutonomousCar() : ConnectedVehicle(){
            carID="0000";
        }

        AutonomousCar(string vehicleName, string cardID) : ConnectedVehicle(vehicleName, 0){
            this->carID=cardID;
        }

        void start() override{
            cout<<"Autonomous Car "<<carID<<" is ready to drive."<<endl;
        }

        void navigateTo(string destination) const{
            cout<<"Driving to "<<destination<<endl;
        }

        void checkDistance(float dist){
            cout<<"Total distance is "<<dist<<" km"<<endl;
            fuelLevel-=(fuelLevel*0.1*dist);
        }

        void selfPark() const{
            cout<<"Car "<<carID<<" is parking itself."<<endl;
        }

        void enableGPS(string ssid) override{
            cout<<"GPS enabled for "<<ssid<<endl;
        }

        void disableGPS() override{
            cout<<"GPS disabled"<<endl;
        }
};

void testVehicle(IVehicle *v) {
    v->start();
    v->stop();
    cout << endl;
}

int main() {
    AutonomousCar car("Tesla", "X");

    car.refuel(100);
    car.start();
    car.enableGPS("City_Network");
    car.navigateTo("Airport");
    car.checkDistance(2);
    car.checkFuel();
    car.refuel(50);
    car.selfPark();
    car.disableGPS();
    car.stop();

    Vehicle v("Toyota");
    ConnectedVehicle cv("BMW", 100);
    AutonomousCar ac("Audi", "A8");

    testVehicle(&v);
    testVehicle(&cv);
    testVehicle(&ac);

    return 0;
}