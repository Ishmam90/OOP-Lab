#include<bits/stdc++.h>
using namespace std;

enum etype{
    laborer, secretary, manager, accountant, executive, researcher
};

int main(){
    char c;
    etype emp;

    cout<<"Enter employee type (first letter only): ";
    cin>>c;

    switch(c){
        case 'l':
            emp=laborer;
            break;

        case 's':
            emp=secretary;
            break;

        case 'm':
            emp=manager;
            break;
        
        case 'a':
            emp=accountant;
            break;

        case 'e':
            emp=executive;
            break;

        case 'r':
            emp=researcher;
            break;
    }

    switch(emp){
        case laborer:
            cout<<"Employee type is laborer.";
            break;

        case secretary:
            cout<<"Employee type is secretary.";
            break;

        case manager:
            cout<<"Employee type is manager.";
            break;

        case accountant:
            cout<<"Employee type is accountant.";
            break;

        case executive:
            cout<<"Employee type is executive.";
            break;
        
        case researcher:
            cout<<"Employee type is researcher.";
            break;
    }
}