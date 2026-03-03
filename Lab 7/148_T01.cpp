#include<iostream>
using namespace std;

class Person{
    private:
        string name;
        int age;
        const int id=1;
        static int count;

    public:
        Person() : id(count++){
            this->name="John Doe";
            this->age=0;
        }

        Person(string name, int age) : id(count++){
            this->name=name;
            this->age=age;
        }

        ~Person(){
            cout<<"Person() is called"<<endl;
        }

        void displayDetails(){
            cout<<name<<", ";
            cout<<"Age: "<<age<<", ";
            cout<<"P_ID: "<<id<<endl;
        }

        void setName(string name){
            this->name=name;
        }

        void setAge(int age){
            this->age=age;
        }

        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

        int getPersonID(){
            return id;
        }

        bool operator==(const Person &other) const{
            if(name==other.name && age==other.age)  return true;
            return false;
        }
};

int Person::count = 1;

class Student : public Person{
    private:
        int sid;

    public:
        int getSid(){
            return sid;
        }

        void setSid(int sid){
            this->sid=sid;
        }
};

class Faculty : public Person{
    private:
        string designation;

    public:
        Faculty() : Person("Mr. X", 22){
            designation="Lecturer";
        }

        Faculty(string name, int age, string designation) : Person(name, age){
            this->designation=designation;
        }

        ~Faculty(){
            cout<<"Faculty() is called"<<endl;
        }
    
        void setDesignation(string designation){
            this->designation=designation;
        }

        string getDesignation(){
            return designation;
        }
};

class Visitor : public Person{
    private:
        string visitingPurpose;

    public:
        string getVisitingPurpose(){
            return visitingPurpose;
        }

        void setVisitingPurpose(string visitingPurpose){
            this->visitingPurpose=visitingPurpose;
        }
};

void TestPerson()
{
    Person p1, p2("Faisal",30);

    if(p1.getName()=="John Doe" && p1.getAge() == 0 &&p1.getPersonID()==1) cout<< "Zero Arg Constructor - Passed"<<endl;
    else  cout<< "Zero Arg Constructor - Failed!!!!"<<endl;

    if(p2.getName()=="Faisal" && p2.getAge() == 30 &&p2.getPersonID()==2) cout<< "Argumented Constructor - Passed"<<endl;
    else  cout<< "Argumented Constructor - Failed!!!!"<<endl;

    if(p1==p1) cout<< " operator == - Passed"<<endl;
    else cout<< " operator == - Failed!!!!"<<endl;

}

void TestStudent(){
    Student s1;
}
void TestFaculty(){
    Faculty f;
    if(f.getName()=="Mr. X"&&f.getAge()==22&&f.getDesignation()=="Lecturer") cout<< "Zero Arg Constructor Faculty - Passed"<<endl;
    else cout<< "Zero Arg Constructor Faculty - Failed!!!!"<<endl;
}
void TestVisitor()
{
    Visitor v;
}

int main()
{
    TestPerson();
    TestStudent();
    TestFaculty();
    TestVisitor();
}
