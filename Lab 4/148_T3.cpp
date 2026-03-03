#include<bits/stdc++.h>
using namespace std;

class FarlinkSatellite{
    private:
        float alt;
        static int active;

    public:
        FarlinkSatellite(){
            alt=430.2;
            active++;
            cout<<"Satellite deployed. Orbit count: "<<active<<endl;
        }

        ~FarlinkSatellite(){
            active--;
            cout<<"Satellite de-orbited and burned up. Orbit count: "<<active<<endl;
        }

        void adjustAltitude(float x){
            if((alt+x)<230.4){
                cout<<"Error"<<endl;
                return;
            }

            alt+=x;
        }

        int getOrbitCount(){
            return active;
        }
};

int main(){

}