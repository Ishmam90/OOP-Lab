#include<iostream>
#include<string>
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

        virtual void displayDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }

        virtual string getRole()const{
            return "General Person";
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

        virtual string getRole()const{
            return "Student";
        }

        void displayDetails(){
            Person::displayDetails();
            cout<<"Student ID: "<<studentID<<endl;
            cout<<"Current CGPA: "<<currentCGPA<<endl;
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

        string getRole()const{
            return "Scholarship Student";
        }

        void displayDetails(){
            Student::displayDetails();
            cout<<"Scholarship Percentage: "<<scholarshipPercentage<<endl;
            cout<<"Minimum CGPA Requirement: "<<minCGPARequirement<<endl;
        }

        void checkEligibility(){
            if(currentCGPA>=minCGPARequirement){
                cout<<"Eligible for Scholarship"<<endl;
            }
            else{
                cout<<"Not Eligible for Scholarship"<<endl;
            }
        }
};

float ScholarshipStudent::minCGPARequirement=0.0;

class Faculty:public Person{
    private:
        string employeeID;
        string department;
        int courseTaught;

    public:
        Faculty(){
            employeeID="0000";
            department="None";
            courseTaught=0;
        }

        Faculty(string employeeID, string department, int courseTaught):Person(){
            this->employeeID=employeeID;
            this->department=department;

            if(courseTaught>=0)  this->courseTaught=courseTaught;
        }

        void displayDetails(){
            Person::displayDetails();
            cout<<"Employee ID: "<<employeeID<<endl;
            cout<<"Department: "<<department<<endl;
            cout<<"Courses Taught: "<<courseTaught<<endl;
        }

        string getRole()const{
            return "Faculty Member";
        }

        void assignNewCourse(){
            courseTaught++;
        }
};

int main(){
    Person* p[4];
    p[0]=new Person("Random", 20);
    p[1]=new Student("2121223", 3.75);
    p[2]=new ScholarshipStudent(50.0, 3.5);
    p[3]=new Faculty("1234", "CSE", 3);

    for(int i=0; i<4; i++){
        p[i]->displayDetails();
        cout<<endl;
    }

    for(int i=0; i<4; i++){
        cout<<p[i]->getRole()<<endl;
    }
}