#include<bits/stdc++.h>
using namespace std;

class SupplyAlert{
    private:
        int current=0;
        int threshold=5;
        string item_id;

    public:
        void setThreshold(int t){
            if(t<=0){
                cout<<"Invalid threshold: must be > 0";
                return;
            }

            threshold=t;
        }

        void setItemID(const char id[]){
            item_id=id;
        }

        void addStock(int n){
            if(n<0){
                cout<<"Invalid stock addition";
                return;
            }

            current+=n;
        }

        void consume(int n){
            if(n<0){
                cout<<"Invalid consumption";
                return;
            }

            current-=n;
        }

        bool isLow(){
            if(current<=threshold)  return true;
            else                    return false;
        }

        void profile(){
            cout<<"Item ["<<item_id<<"]"<<endl;
            cout<<"Stock ["<<current<<"]"<<endl;
            cout<<"Threshold ["<<threshold<<"]"<<endl;

            if(isLow()) cout<<"[LOW]"<<endl;
            else        cout<<"[OK]"<<endl;
        }
};  