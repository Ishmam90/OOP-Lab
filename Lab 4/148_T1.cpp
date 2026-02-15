#include<bits/stdc++.h>
using namespace std;

class CoffeeMaker{
    private:
        int water;
        int beans;
        int max_cap;

    public:
        CoffeeMaker(const int w){
            water=0;
            beans=0;
            max_cap=w;
        }

        ~CoffeeMaker(){
            cout<<"Shutting down system. Cleaning internal pipes"<<endl;
        }

        void addResources(int w, int b){
            if(w<0 || b<0 || w+water>max_cap || b+beans>max_cap){
                cout<<"Error"<<endl;
                return;
            }

            water+=w;
            beans+=b;
        }

        void brewCup(int strength){
            if(strength<1 || strength>3){
                cout<<"Error"<<endl;
                return;
            }

            if((water-150)<=0){
                cout<<"Refill needed for water"<<endl;
                return;
            }
            else    water-=150;

            if(beans-(strength*7)<=0){
                cout<<"Refill needed for beans"<<endl;
                return;
            }
            else    beans-=(strength*7);                
        }

        void reportStatus(){
            cout<<beans<<endl;
            cout<<((float)water/(float)max_cap)*(float)100<<"%"<<endl;
        }
};

int main(){

}