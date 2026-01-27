#include<bits/stdc++.h>
using namespace std;

class BatchMeter{
    private:
        int total=0;
        int pulseSize=1;

    public:
        void setPulseSize(int s){
            if(s<=0)    cout<<"Invalid pulse; must be > 0";
            else pulseSize=s;
        }

        int getTotal(){
            return total;
        }

        void addPulse(){
            total+=pulseSize;
        }

        void clear(){
            total=0;
        }
};