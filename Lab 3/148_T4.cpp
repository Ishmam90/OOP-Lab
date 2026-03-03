#include<bits/stdc++.h>
using namespace std;

class EventTime{
    private:
        long hour;
        long minute;
        long second;

    public:
        int getHour(){
            return  hour;
        }

        int getMinute(){
            return  minute;
        }

        int getSecond(){
            return  second;
        }

        void setTime(long h, long m, long s){
            if(h < 0 || m < 0 || s < 0){
                cout << "Invalid";
                return;
            }

            m+=(s/60);
            s%=60;

            h+=(m/60);
            m%=60;

            h%=24;

            hour=h;
            minute=m;
            second=s;
        }

        void addDuration(long h, long m, long s){
            if(h < 0 || m < 0 || s < 0){
                cout << "Invalid";
                return;
            }
            
            second+=s;
            minute+=m;
            hour+=h;

            minute+=(second/60);
            second%=60;

            hour+=(minute/60);
            minute%=60;

            hour%=24;
        }

        void printTime(){
            if(hour<10)     cout<<"0"<<hour<<":";
            else            cout<<hour<<":";

            if(minute<10)   cout<<"0"<<minute<<":";
            else            cout<<minute<<":";

            if(second<10)   cout<<"0"<<second<<":";
            else            cout<<second<<":";
        }
};