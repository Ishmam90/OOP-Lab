#include<iostream>
using namespace std;

class IExplorer{
    public:
        virtual void observe()=0;
        virtual void report()=0;
};

class IDataCollector{
    public:
        virtual void collectSample(string sampleType)=0;
        virtual void storeData()=0;
};

class BasicExplorer : public IExplorer{
    protected:
        string name;

    public:
        BasicExplorer(){
            name="Unknown";
        }

        BasicExplorer(string name){
            this->name=name;
        }

        void observe() override{
            cout<<"Explorer "<<name<<" is observing the area."<<endl;
        }

        void report() override{
            cout<<"Explorer "<<name<<" reports general findings."<<endl;
        }

        void introduce() const{
            cout<<"Hello, I am "<<name<<", a basic explorer."<<endl;
        }
};

class FieldScientist : public IExplorer, public IDataCollector{
    protected:
        string name;
        int fieldExperience;

    public:
        FieldScientist(){
            name="Unknown";
            fieldExperience=5;
        }

        FieldScientist(string name, int fieldExperience){
            this->name=name;
            this->fieldExperience=fieldExperience;
        }

        void observe() override{
            cout<<"FieldScientist "<<name<<" is observing with "<<fieldExperience<<" years of experience."<<endl;
        }

        void collectSample(string sampleType) override{
            cout<<"Collecting "<<sampleType<<" sample."<<endl;
        }

        void report() override{
            cout<<"Report"<<endl;
        }

        void storeData() override{
            cout<<"Data stored"<<endl;
        }

        void analyzeSample(string sampleType){
            cout<<"Analyzing "<<sampleType<<" sample."<<endl;
        }

        void showExperience(){
            cout<<"Experience: "<<fieldExperience<<" years"<<endl;
        }
};

class EcoDrone : public FieldScientist{
    protected:
        string droneID;

    public:
        EcoDrone() : FieldScientist(){}

        EcoDrone(string name, int fieldExperience, string droneID) : FieldScientist(name, fieldExperience){
            this->droneID=droneID;
        }

        void observe() override{
            cout<<"Drone "<<droneID<<" is scanning the environment from above."<<endl;
        }

        void mapTerrain() const{
            cout<<"Mapping terrain using drone "<<droneID<<endl;
        }

        void trackingAnimal(string species) const{
            cout<<"Drone "<<droneID<<" is tracking "<<species<<endl;
        }

        void performMaintenance() const{
            cout<<"Drone "<<droneID<<" performing maintenance check."<<endl;
        }
};

int main(){
    EcoDrone drone("Alex", 8, "DR-101");

    drone.observe();
    drone.collectSample("water");
    drone.analyzeSample("water");
    drone.mapTerrain();
    drone.trackingAnimal("tiger");
    drone.performMaintenance();
    drone.report();
}
