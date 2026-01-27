#include<iostream>
using namespace std;

class Person{
    private:
        string name;
        int age;

    public:
        Person(){
            name="None";
            age=0;
        }

        Person(string name, int age){
            this->name=name;

            if(age>0)   this->age=age;
            else        return;
        }

        void displayDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }
};

class Student:public Person{
    protected:
        string studentID;
        float currentCGPA;

    public:
        Student(){
            studentID="0000000";
            currentCGPA=0.0;
        }

        Student(string studentID, float currentCGPA) : Person(){
            this->studentID=studentID;

            if(currentCGPA>0.0 && currentCGPA<=4.0) this->currentCGPA=currentCGPA;
        }

        void updateCGPA(float cgpa){
            if(cgpa>0.0 && cgpa<=4.0)   currentCGPA=cgpa;
        }
};

class ScholarshipStudent:public Student{
    private:
        float scholarshipPercentage;
        static float minCGPARequirement;

    public:
        ScholarshipStudent(){
            scholarshipPercentage=0.0;
            minCGPARequirement=0.0;
        }

        ScholarshipStudent(float scholarshipPercentage, float minCGPARequirement):Student(){
            if(scholarshipPercentage>0 && scholarshipPercentage<=100)   this->scholarshipPercentage=scholarshipPercentage;
            if(minCGPARequirement>2.0 && minCGPARequirement<=4.0)       this->minCGPARequirement=minCGPARequirement;
        }
};

int main(){

}