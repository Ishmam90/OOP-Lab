#include<bits/stdc++.h>
using namespace std;

class meme{
    private:
        string memeName;
        int originYear;
        int humorScore;
        bool isStillViral;

    public:
        meme(){
            this->memeName="Lost Meme";
            this->originYear=2010;
            this->humorScore=50;
            this->isStillViral=false;
        }

        meme(string memeName, int humorScore, int originYear, bool isStillViral){
            this->memeName=memeName;
            this->originYear=2010;
            this->humorScore=humorScore;
            this->isStillViral=isStillViral;
        }

        string get_meme(){
            return  memeName;
        }

        void insert_meme(string s){
            memeName=s;
        }

        int get_origin_year(){
            return originYear;
        }

        void insert_origin_year(int year){
            if(year>=2000 && year<=2025)
                originYear=year;
            else    
                originYear=2010;
        }

        int get_humorScore(){
            return humorScore;
        }

        void insert_humor_score(int score){
            if(score>=1 && score<=100)
                humorScore=score;
            else
                humorScore=50;
        }

        bool get_viral(){
            return isStillViral;
        }

        bool set_viral(bool x){
            isStillViral=x;
        }
};

void archiveMemes(meme collection[], int size){
    string name;
    int year, score;
    bool viral;

    for(int i=0; i<size; i++){
        cin>>name;
        cin>>year;
        cin>>score;
        cin>>viral;

        collection[i].insert_meme(name);
        collection[i].insert_origin_year(year);
        collection[i].insert_humor_score(score);
        collection[i].set_viral(viral);
    }
}

int main(){
    meme collection[40];

    archiveMemes(collection, 5);

    srand(time(0));

    for(int i=5; i<40; i++){
        int rand_year=2000+(rand()%26);
        int rand_score=1+(rand()%100);

        collection[i].insert_meme("Lost Meme");
        collection[i].insert_origin_year(rand_year);
        collection[i].insert_humor_score(rand_score);
        collection[i].set_viral(false);
    }

    for(int i=0; i<40; i++){
        int year, score;

        year=collection[i].get_origin_year();
        score=collection[i].get_humorScore();

        if(year<2010 && score>70){
            cout<<collection[i].get_meme()<<endl;
            cout<<collection[i].get_origin_year()<<endl;
            cout<<collection[i].get_humorScore()<<endl;
            cout<<collection[i].get_viral()<<endl;
        }
    }
}