#include<iostream>
using namespace std;

class PlayerStat{
    private:
        long xp;
        int gold;
        string username;

    public:
        PlayerStat(long xp, int gold, string username){
            if(xp>=0)   this->xp=xp;
            else        this->xp=0;

            if(gold>=0) this->gold=gold;
            else        this->gold=0;

            this->username=username;
        }

        ~PlayerStat(){
            cout<<"End"<<endl;
        }

        void set_xp(long exp){
            if(exp>=0)  xp=exp;
            else{
                cout<<"Error"<<endl;
                return;
            }
        }

        void set_gold(int gd){
            if(gd>=0)  gold=gd;
            else{
                cout<<"Error"<<endl;
                return;
            }
        }

        void set_username(string name){
            username=name;
        }

        long get_xp(){
            return xp;
        }

        int get_gold(){
            return gold;
        }

        string get_username(){
            return username;
        }

        PlayerStat operator+=(PlayerStat &merge_party) const{
            merge_party.xp+=xp;
            merge_party.gold+=gold;

            return merge_party;
        }

        PlayerStat operator+=(int gd) const{
            return PlayerStat(xp, gold+gd, username);
        }

        bool operator==(PlayerStat player) const{
            if(player.xp==xp && player.gold)    return true;
            else    false;
        }

        bool operator!=(PlayerStat player) const{
            if(player.xp==xp && player.gold)    return false;
            else    true;
        }

        bool operator>=(PlayerStat player) const{
            if(player.xp>xp)    return true;
            else    false;
        }
};

int main(){

}