#include<bits/stdc++.h>
using namespace std;

int main(){
    int height, total=0;

    cout<<"Enter maximum height: ";
    cin>>height;

    for(int i=0; i<3; i++){
        if(i==0){
            total=height;
            cout<<"Height after "<<i+1<<" hour "<<total<<endl;
        }
        else{
            total+=height/2;
            height/=2;
            cout<<"Height after "<<i+1<<" hour "<<total<<endl;
        }
    }
}