#include<bits/stdc++.h>
using namespace std;

class GridNavigator{
    private:
        double home_x=0.0, home_y=0.0;
        double current_x=0.0, current_y=0.0;

    public:
        void setHome(double x, double y){
            home_x=x;
            home_y=y;

            if(current_x==0.0 && current_y==0.0){
                current_x=home_x;
                current_y=home_y;
            }
        }

        void moveBy(double dx, double dy){
            current_x+=dx;
            current_y+=dy;
        }

        void resetToHome(){
            current_x=home_x;
            current_y=home_y;
        }

        double getX(){
            return      current_x;
        }

        double getY(){
            return      current_y;
        }

        double distanceTo(double x, double y){
            return      sqrt(((x-current_x)*(x-current_x))+((y-current_y)*(y-current_y)));
        }

        void printLocation(){
            cout<<current_x<<" "<<current_y;
        }
};  