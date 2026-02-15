#include<bits/stdc++.h>
using namespace std;

class stockPortfolio{
    private:
        string ownerName;
        double totalValue;
        int riskVolatility;
        int stockCount;

    public:
        stockPortfolio(){
            this->ownerName=ownerName;
            this->totalValue=totalValue;
            this->riskVolatility=riskVolatility;
            this->stockCount=stockCount;
        }

        stockPortfolio(string ownerName, double totalValue, int riskVolatility, int stockCount){
            this->ownerName=ownerName;
            this->totalValue=totalValue;
            this->riskVolatility=riskVolatility;
            this->stockCount=stockCount;
        }

        string get_name(){
            return ownerName;
        }

        void set_name(string s){
            ownerName=s;
        }

        double get_value(){
            return totalValue;
        }

        void set_value(double x){
            totalValue=x;
        }

        int get_risk(){
            return riskVolatility;
        }

        void set_risk(int x){
            if(x>=1 && x<=10)
                riskVolatility=x;
        }

        int get_stock(){
            return stockCount;
        }

        void set_count(int x){
            stockCount=x;
        }
};