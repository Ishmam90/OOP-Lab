#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

class MenuItem {
  private:
    int id;
    string name;
    double price;

  public:
    MenuItem() {
        id = 0;
        name = "Unknown";
        price = 0.0;
    }

    MenuItem(int id, string name, double price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    string serialize() const {
        stringstream ss;
        ss << id << "|" << name << "|" << price << endl;
        return ss.str();
    }

    static bool deserialize(const string &line, MenuItem &out) {
        stringstream ss(line);
        string temp;
        string parts[3];
        int i = 0;

        while (getline(ss, temp, '|') && i < 3) {
            parts[i++] = temp;
        }

        if (i != 3) return false;

        return true;
    }

    static void printHeader(ostream &os){
        os << left << setw(6) << "ID" << setw(20) << "Item" << right << setw(10) << "Price" << endl;
    }

    void printRow(ostream &os){
        os << left << setw(6) << id << setw(20) << name << right << setw(10) << fixed << setprecision(2) << price << endl;
    }
};

bool recordSale(const string &salesFile, int saleID, const MenuItem &mn, int units){
    ofstream fout(salesFile, ios::app);
}

int main(){}