#include<iostream>
#include<string>
using namespace std;

class AutonomusUnit{
    protected:
        string unitID;
        bool operationalStatus;

    public:
        AutonomusUnit(){
            unitID="0000";
            operationalStatus=false;
        }

        AutonomusUnit(string unitID, bool operationalSatus){
            this->unitID=unitID;
            this->operationalStatus=operationalSatus;
        }

        virtual ~AutonomusUnit(){
            cout<<"Autonomus Unit Shutting Down"<<endl;
        }

        string getUnitType()const{
            return "General Autonomus Unit";
        }

        void diagnosticCheck(){
            if(operationalStatus)   cout<<"Active"<<endl;
            else                    cout<<"Inactive"<<endl;
        }

        virtual void executeMission()=0;
};

class VehicleUnit:virtual public AutonomusUnit{
    protected:
        int maxSpeed;
        float fuelLevel;
        int currentLocationX;
        int currentLocationY;

    public:
        VehicleUnit(){
            maxSpeed=50;
            fuelLevel=50.0;
            currentLocationX=0;
            currentLocationY=0;
        }

        VehicleUnit(string id, bool status, int maxSpeed, int fuelLevel, int x, int y) : AutonomusUnit(id, status), maxSpeed(maxSpeed), fuelLevel(fuelLevel), currentLocationX(x), currentLocationY(y){}

        ~VehicleUnit(){
            cout<<"Vehicle going Dark";
        }

        void setMax(int max){
            if(max>0)   maxSpeed=max;
        }

        void setLevel(float level){
            if(level>=0 && level<=100)  fuelLevel=level;
        }

        void set_locationX(int x){
            if(x>=0)    currentLocationX=x;
        }

        void set_locationY(int y){
            if(y>=0)    currentLocationY=y;
        }

        int getMax()const{
            return maxSpeed;
        }

        float getLevel()const{
            return fuelLevel;
        }

        int get_locationX()const{
            return currentLocationX;
        }

        int get_locationY()const{
            return currentLocationY;
        }

        void move(){
            if(fuelLevel!=0)    fuelLevel--;
            cout<<"Moving at speed "<<maxSpeed<<endl;
            cout<<"Fuel remaining "<<fuelLevel<<endl;
        }

        void executeMission(){
            cout<<"Executing Vehicle Unit Mission"<<endl;
        }

        string getUnitType()const{
            return "Vehicle Unit";
        }
};

class CameraUnit:virtual public AutonomusUnit{
    protected:
        bool nightVisionMode;
        int storageCapacity;
        string recordingQuality;

    public:
        CameraUnit(){
            nightVisionMode=false;
            storageCapacity=0;
            recordingQuality="HD";
        }

        CameraUnit(bool nightVisionMode, int storageCapacity, string recordingQuality){
            this->nightVisionMode=nightVisionMode;
            if(storageCapacity>0)   this->storageCapacity=storageCapacity;
            if(recordingQuality=="HD" || recordingQuality=="Full HD" || recordingQuality=="4K") this->recordingQuality=recordingQuality;
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

        void setQuality(string quality){
            if(quality=="HD" || quality=="Full HD" || quality=="4K") recordingQuality=quality;
        }

        bool getNightVision()const{
            return nightVisionMode;
        }

        int getCap()const{
            return storageCapacity;
        }

        string getQuality()const{
            return recordingQuality;
        }

        void recordFootage(){
            if(storageCapacity>0){
                storageCapacity--;
                cout<<"Recording… Night vision is ";
                if(nightVisionMode) cout<<"On"<<endl;
                else                cout<<"Off"<<endl;
                cout<<"Storage remaining: "<<storageCapacity<<" GB"<<endl;
            }
        }

        void executeMission(){
            cout<<"Executing Camera Unit Mission"<<endl;
        }

        string getUnitType()const{
            return "Surveillance Unit";
        }
};

class WeaponArm{
    private:
        int ammoCount;
        int damage;
        string weaponType;

    public:
        WeaponArm(){
            ammoCount=0;
            damage=0;
            weaponType="None";
        }

        WeaponArm(int ammoCount, int damage, string weaponType){
            if(ammoCount>0) this->ammoCount=ammoCount;
            if(damage>0)    this->damage=damage;
            if(weaponType=="Kinetic" || weaponType=="Energy") this->weaponType=weaponType;
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

        void setWeaponType(string type){
            if(type=="Kinetic" || type=="Energy") weaponType=type;
        }

        int getAmmo()const{
            return ammoCount;
        }

        int getDamage()const{
            return damage;
        }

        string getWeaponType()const{
            return weaponType;
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

        void getWeaponInfo()const{
            cout<<"Weapon Type: "<<weaponType<<endl;
            cout<<"Ammo Count: "<<ammoCount<<endl;
            cout<<"Damage per Shot: "<<damage<<endl;
        }
};

class MissionObjective{
    public:
        virtual void planExecution()=0;
        virtual void execute()=0;
        
        virtual string getMissionType()const{
            return "Mission Classification";
        }

        int difficultyLevel()const{
            return 5;
        }
};

class ReconMission:public MissionObjective{
    private:
        string areaToScan;
        int intelPriority;

    public:
        ReconMission(){
            areaToScan="Unknown";
            intelPriority=1;
        }

        ReconMission(string areaToScan, int intelPriority){
            this->areaToScan=areaToScan;
            if(intelPriority>0)   this->intelPriority=intelPriority;
        }

        void planExecution()override{
            cout<<"Planning reconnaissance of "<<areaToScan<<" Priority: "<<intelPriority<<endl;
        }

        void execute() override{
            cout<<"Executing stealth serveillance protocol."<<endl;
        };

        string getMissionType()const{
            return "Reconnaissance";
        }
};

class PatrolBot:public VehicleUnit, CameraUnit{
    private:
        string modelNumber;
        WeaponArm WArm;
        MissionObjective** assignedMission;
        int missionCount;
        int missionCapacity;

    public:
        PatrolBot():VehicleUnit(), CameraUnit(){
            modelNumber="X";
            missionCount=0;
            missionCapacity=0;
            assignedMission=NULL;
        }

        PatrolBot(string id, bool status, int maxSpeed, float fuel, int x, int y, bool nightVision, int storage, string quality, string modelNumber, WeaponArm weapon, int missionCapacity)
            : AutonomusUnit(id, status),
              VehicleUnit(id, status, maxSpeed, fuel, x, y),
              CameraUnit(nightVision, storage, quality),
              modelNumber(modelNumber),
              WArm(weapon){
            missionCount = 0;
            this->missionCapacity=missionCapacity;
            assignedMission = new MissionObjective*[missionCapacity];
        }

        ~PatrolBot(){
            delete[] assignedMission;
            cout<<modelNumber<<" going Dark"<<endl;
        }

        void patrolArea(){
            move();
            recordFootage();
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

        void assignMission(MissionObjective* mission){
            if(missionCount < missionCapacity)
                assignedMission[missionCount++] = mission;
        }

        void executeAllMissions(){
            for(int i = 0; i < missionCount; i++){
                assignedMission[i]->planExecution();
                assignedMission[i]->execute();
            }
        }

        int getCapability()const{
            return missionCount;
        }

        virtual void getCapabilityReport()const{
            cout<<"Patrol Bot Mission Capability: "<<missionCount<<endl;
        }

        void reloadWeapon(int amount){
            WArm.reload(amount);
        }

        void executeMission() override{
            VehicleUnit::executeMission();
        }
};

class DefenseMission:public MissionObjective{
    private:
        string perimeterToGuard;
        int threatLevel;

    public:
        DefenseMission(string area="Base", int threat=1)
            : perimeterToGuard(area), threatLevel(threat){}

        void planExecution() override{
            cout<<"Establishing defense at "<<perimeterToGuard<<". Threat: "<<threatLevel<<endl;
        }

        void execute() override{
            cout<<"Activating defensive countermeasures."<<endl;
        }

        string getMissionType()const override{
            return "Defense";
        }
};


int main(){
    WeaponArm weapon(3, 50, "Kinetic");

    PatrolBot bot(
        "P-01", true,
        80, 50.0, 0, 0,
        true, 100, "4K",
        "X9",
        weapon,
        5
    );

    cout <<"PATROL"<<endl;
    bot.patrolArea();

    cout <<"ENGAGING TARGET"<<endl;
    bot.engageTarget();
    bot.engageTarget();
    bot.engageTarget();
    bot.engageTarget(); // out of ammo

    cout <<"RELOADING"<<endl;
    bot.reloadWeapon(5);

    ReconMission r1("Sector 7", 3);
    DefenseMission d1("Main Gate", 5);

    bot.assignMission(&r1);
    bot.assignMission(&d1);

    cout <<"EXECUTING MISSIONS"<<endl;
    bot.executeAllMissions();
}