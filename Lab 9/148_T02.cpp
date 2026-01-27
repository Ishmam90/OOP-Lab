#include<iostream>
using namespace std;

class VehicleUnit{
    protected:
        int maxSpeed;
        float fuelLevel;

    public:
        VehicleUnit(){
            maxSpeed=50;
            fuelLevel=50.0;
        }

        VehicleUnit(int maxSpeed, int fuelLevel){
            if(maxSpeed>0)                      this->maxSpeed=maxSpeed;
            if(fuelLevel>=0 && fuelLevel<=100)  this->fuelLevel=fuelLevel;
        }

        ~VehicleUnit(){
            cout<<"Vehicle going Dark";
        }

        void setMax(int max){
            if(max>0)   maxSpeed=max;
        }

        void setLevel(float level){
            if(level>=0 && level<=100)  fuelLevel=level;
        }

        int getMax()const{
            return maxSpeed;
        }

        float getLevel()const{
            return fuelLevel;
        }

        void move(){
            if(fuelLevel!=0)    fuelLevel--;
            cout<<"Moving at speed "<<maxSpeed<<endl;
            cout<<"Fuel remaining "<<fuelLevel<<endl;
        }
};

class CameraUnit{
    protected:
        bool nightVisionMode;
        int storageCapacity;

    public:
        CameraUnit(){
            nightVisionMode=false;
            storageCapacity=0;
        }

        CameraUnit(bool nightVisionMode, int storageCapacity){
            this->nightVisionMode=nightVisionMode;
            if(storageCapacity>0)   this->storageCapacity=storageCapacity;
        }

        ~CameraUnit(){
            cout<<"Camera going dark"<<endl;
        }

        void setNightVision(bool nightVision){
            nightVisionMode=nightVision;
        }

        void setCap(int cap){
            if(cap>0)   storageCapacity=cap;
        }

        bool getNightVision()const{
            return nightVisionMode;
        }

        int getCap()const{
            return storageCapacity;
        }

        void recordFootage(){
            cout<<"Recording… Night vision is ";
            if(nightVisionMode) cout<<"On"<<endl;
            else                cout<<"Off"<<endl;
        }
};

class WeaponArm{
    private:
        int ammoCount;
        int damage;

    public:
        WeaponArm(){
            ammoCount=0;
            damage=0;
        }

        WeaponArm(int ammoCount, int damage){
            if(ammoCount>0) this->ammoCount=ammoCount;
            if(damage>0)    this->damage=damage;
        }

        ~WeaponArm(){
            cout<<"Weapon going dark"<<endl;
        }

        void setAmmo(int ammo){
            if(ammo>0)  ammoCount=ammo;
        }

        void setDamage(int damage){
            if(damage>=0)   this->damage=damage;
        }

        int getAmmo()const{
            return ammoCount;
        }

        int getDamage()const{
            return damage;
        }

        void fire(){
            if(ammoCount>0){
                ammoCount--;
                cout<<"Bang! Dealt "<<damage<<" damage."<<endl;
            }

            else    cout<<"Click… Out of ammo."<<endl;
        }

        void reload(int amount){
            ammoCount+=amount;
        }
};

class PatrolBot:public VehicleUnit, CameraUnit{
    private:
        string modelNumber;
        WeaponArm WArm;

    public:
        PatrolBot():VehicleUnit(), CameraUnit(){
            modelNumber="X";
        }

        PatrolBot(VehicleUnit VUnit, CameraUnit CUnit, string modelNumber, WeaponArm WArm){
            VehicleUnit(VUnit);
            CameraUnit(CUnit);
            this->modelNumber=modelNumber;
            this->WArm=WArm;
        }

        ~PatrolBot(){
            cout<<modelNumber<<" going Dark"<<endl;
        }

        void patrolArea(){
            move();
        }

        void engageTarget(){
            WArm.fire();
        }

        void statusReport(){
            cout<<getMax()<<endl;
            cout<<getLevel()<<endl<<endl;

            recordFootage();
            cout<<endl;
            cout<<storageCapacity<<endl<<endl;

            cout<<WArm.getAmmo()<<endl;
            cout<<WArm.getDamage()<<endl;
        }
};