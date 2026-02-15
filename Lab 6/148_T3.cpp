#include<iostream>
using namespace std;

class elevator{
    private:
        int curr_floor;
        const int max_floor;

    public:
        elevator(int curr_floor, int m) : max_floor(m){
            this->curr_floor=curr_floor;
        }

        ~elevator(){
            cout<<"Destroyed"<<endl;
        }

        void set_current(int current){        
            if(current>=0 && current<=max_floor){
                curr_floor=current;
            }
            else{
                cout<<"Error"<<endl;
                return;
            }
        }

        int get_current(){
            return curr_floor;
        }

        int get_max(){
            return max_floor;
        }

        elevator operator--() {
            if (curr_floor == 0) {
                cout << "Ground Floor Reached" << endl;
            } 
            else {
                --curr_floor;
            }
            return *this;
        }

        elevator operator--(int) {
            elevator temp(*this);   
            (*this)--;
            return temp;
        }

        friend ostream& operator<<(ostream &stream, const elevator &el){
            stream<<"Elevator is currently at Floor: "<<el.curr_floor<<endl;
            return stream;
        }

        friend istream& operator>>(istream &stream, const elevator &el){
            int current;
            stream>>current;
            return stream;
        }
};

int main(){

}