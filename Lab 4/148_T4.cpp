#include<bits/stdc++.h>
using namespace std;

class RaceCar{
    private:
        const int max;
        double current;

    public:
        RaceCar(int m) : max(m){
            current=0;
        }

        ~RaceCar(){
            cout<<"Car returned to garage"<<endl;
        }

        void accelerate(double x){
            if(x>max){
               cout<<"Velocity limit exceeded. Please consult the laws of physics."<<endl;
               return;
            }

            current+=x;
        }

        bool isFasterThan(RaceCar r){
            if(r.current>current)   return  false;
            return  true;
        }

        void dashboard(){
            cout<<current<<endl;
            cout<<max<<endl;
        }
};

int main(){

}