#include <bits/stdc++.h>
using namespace std;
class Classroom{
    //use book logic to create a classroom class
    //make Displaying more readable
    public:
    class Student{
        public:
        int StudentID;
        string name;
        int age;
        string grade;
        Student(int StudentID,string name,int age,string grade){
            this->StudentID = StudentID;
            this->name = name;
            this->age = age;
            this->grade = grade;
        }
    };
    int ClassID;
    vector <Student> students;
    Classroom(int i){
        ClassID = i;
    }
    void AddStudent(int StudentID,string name,int age,string grade){
        students.push_back(Student(StudentID,name,age,grade));
    }
    void Remove(int StudentID){
        for (auto i=0;i<students.size();i++){
            if (students[i].StudentID == StudentID){
                students.erase(students.begin()+i);
                break;
            }
        }
    }
    void Display(){
        cout<<"Displaying the students of class "<<ClassID<<endl;
        cout<<"================================================================"<<endl;
        for (auto i:students){
            cout <<"Student ID = "<< i.StudentID <<endl;
            cout<<"Name = "<<i.name <<endl;
            cout<< "Age = " << i.age <<endl;
            cout<< "Grade = " << i.grade <<endl;
        }
        cout<<"================================================================"<<endl;
    }
};
int main(){
    int ClassID = 0;
    Classroom C = Classroom(ClassID);
    C.AddStudent(1,"A",16,"A");
    C.AddStudent(2,"B",17,"B");
    C.AddStudent(3,"C",18,"C");
    cout<<"Before removing the student"<<endl;
    C.Display();
    C.Remove(2);
    cout<<"After removing the student"<<endl;
    C.Display();
    //create new classroomS
    ClassID++;
    Classroom C2 = Classroom(ClassID);
    //create new list
    C2.AddStudent(11,"A",16,"A");
    C2.AddStudent(12,"B",17,"B");
    C2.AddStudent(13,"C",18,"C");
    cout<<"Before removing the student"<<endl;
    C2.Display();
    C2.Remove(12);
    cout<<"After removing the student"<<endl;
    C2.Display();
}