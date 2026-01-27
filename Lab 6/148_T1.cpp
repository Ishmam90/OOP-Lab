#include<iostream>
using namespace std;

class DataPack{
    private:
        float giga;
        string provider;
        bool available;

    public:
        DataPack(const string &provider, float giga){
            this->giga=0.0;
            this->provider="name";
            this->available=false;
        }

        ~DataPack(){
            cout<<"Connection Terminated"<<endl;
        }

        void set_giga(float data){
            if(data<0){
                cout<<"Error"<<endl;
                return;
            }
            else{
                giga=data;
            }
        }

        void set_provider(string name){
            provider=name;
        }

        void set_available(bool x){
            available=x;
        }

        float get_giga(){
            return giga;
        }

        string get_provider(){
            return provider;
        }

        bool get_available(){
            return available;
        }

        DataPack operator+(DataPack &data) const{
            data.giga+=giga;
            data.available=true;
            return data;
        }

        DataPack operator-(DataPack &data) const{
            if(data.giga-giga>0){
                data.giga-=giga;
                return data;
            }
            else{
                data.giga=0;
                data.available=false;
                return data;
            }
        }

        int convert(){
            return 1024*(int)giga;
        }

        void print(){
            cout<<giga<<endl;
            cout<<provider<<endl;
            cout<<available<<endl;
        }
};

int main(){

}