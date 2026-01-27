#include<bits/stdc++.h>
using namespace std;

class PaladinHero{
    private:
        int level;
        int base_dmg;
        int mana;

        int calculateHolyDamage(int lvl, const int dmg, int mn){
            return (lvl*2)+dmg+((10*mn)/100);
        }

    public:
        PaladinHero(int lvl, int dmg, int mn){
            level=lvl;
            base_dmg=dmg;
            mana=mn;
        }

        ~PaladinHero(){
            cout<<"The hero has fallen"<<endl;
        }

        void attackMonster(){
            int x=calculateHolyDamage(level, base_dmg, mana);
            cout<<x<<endl;
            mana--;
        }

        void restAndRecover(int x){
            mana+=x;
            level++;
        }
};

int main(){

}