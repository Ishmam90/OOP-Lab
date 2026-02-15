#include<bits/stdc++.h>
using namespace std;

class CyberImplant{
    private:
        string modelName;
        string bodyPart;
        int powerConsumption;
        double firmwareVersion;

    public:
        CyberImplant(){
            this->modelName=modelName;
            this->bodyPart=bodyPart;
            this->powerConsumption=powerConsumption;
            this->firmwareVersion=1.0;
        }

        CyberImplant(string modelName, string bodyPart, int powerConsumption, double firmwareVersion){
            this->modelName=modelName;
            this->bodyPart=bodyPart;
            this->powerConsumption=powerConsumption;
            this->firmwareVersion=firmwareVersion;
        }

        string get_model(){
            return modelName;
        }

        void set_model(string s){
            modelName=s;
        }

        string get_body(){
            return bodyPart;
        }

        void set_body(string s){
            if(s=="Arm" || s=="Leg" || s=="Eye" || s=="Heart")
                bodyPart=s;
            else
                bodyPart="Auxiliary";
        }

        int get_power(){
            return powerConsumption;
        }

        void set_power(int x){
            if(x<0) return;

            if(x>1000)  powerConsumption=1000;
            else        powerConsumption=x;
        }

        double get_firmware(){
            return firmwareVersion;
        }

        void set_firmware(double x){
            firmwareVersion=x;
        }
};

void upgradeFirmware(CyberImplant &implant){
    implant.set_firmware(implant.get_firmware()+0.1);
    implant.set_power(implant.get_power()-5);
}

int main(){
    CyberImplant ci[5];

    for(int i=0; i<5; i++){
        string a, b;
        int c;
        double d;
        
        cin>>a;
        cin>>b;
        cin>>c;
        cin>>d;

        ci[i].set_model(a);
        ci[i].set_body(b);
        ci[i].set_power(c);
        ci[i].set_firmware(d);

        upgradeFirmware(ci[i]);

        cout<<ci[i].get_model()<<endl;
        cout<<ci[i].get_body()<<endl;
        cout<<ci[i].get_power()<<endl;
        cout<<ci[i].get_firmware()<<endl;
    }
}