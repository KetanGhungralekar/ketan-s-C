#include <bits/stdc++.h>
using namespace std;

struct Student {
    int Student_id;
    string name;
    vector<int> scores;
    int average;
    Student(){
        scores = vector<int> (5);
    }
};
int calculate_Average(Student &obj){
    int sum = 0;
    for (auto i:obj.scores){
        sum += i;
    }
    obj.average = sum/5;
    return (sum/5);
}
Student Find_highest(vector <Student> &obj){
    Student max1;
    int max2 = INT_MIN;
    for (auto &i:obj){
        calculate_Average(i);
    }
    for (auto &i:obj){
        if (max2 < i.average){
            max2 = i.average;
            max1 = i;
        }
    }
    return max1;
}
void Swap_students(vector <Student> &v,int i,int j){
    swap(v[i].scores,v[j].scores);
    calculate_Average(v[i]);
    calculate_Average(v[j]);
}
void Display_student_information(Student *obj){
    cout<<"Student ID :"<<obj->Student_id<<endl;
    cout<<"Name :"<<obj->name<<endl;
    cout<<"Scores : ";
    for (auto i:obj->scores){
        cout<<i<<" ";
    }
    cout<<endl;
}
void Menu(vector <Student> &v){
    while (true){
        cout<<"Enter 1 to calculate and display the average score for each student."<<endl;
        cout<<"Enter 2 to find and display the highest scorer."<<endl;
        cout<<"Enter 3 to swap scores between two students"<<endl;
        cout<<"Enter 4 to display the information for all students."<<endl;
        cout<<"Enter 5 to exit the program"<<endl;
        int choice;
        cin>>choice;
        if (choice == 5){
            return;
        }
        else if (choice == 1){
            for (auto &i:v){
                calculate_Average(i);
                cout<<"Average of Student "<<i.Student_id<<" = "<<i.average<<endl;
            }
        }
        else if (choice == 2){
            cout<<"Highest Scorer is "<<endl;
            Student high = Find_highest(v);
            Display_student_information(&high);
        }
        else if (choice == 3){
            int i,j;
            cout<<"Student ids : ";
            cin>>i>>j;
            Swap_students(v,i-1,j-1);
        }
        else if (choice == 4){
            for (auto i:v){
                Display_student_information(&i);
            }
        }
        else{
            cout<<"Please Enter Valid Choice"<<endl;
        }
    }
}
int main(){
    string s;
    cin>>s;
    cout<<s;
    return 0;
    int n;
    cout<<"Enter No of students :";
    cin>>n;
    vector <Student> v;
    for (int i=0;i<n;i++){
        Student obj;
        cout<<"Enter the Student_ID of student "<<i+1<<" "<<": ";
        cin>>obj.Student_id;
        cout<<"Enter the name of Student : ";
        cin>>obj.name;
        cout<<"Enter the Subject scores : ";
        vector <int> scores(5);
        int j = 0;
        while (j < 5){
            int c;
            cin>>c;
            if (c <= 100 && c >= 0){
                scores[j] = c;
                j++;
            }
            else{
                cout<<"Please Enter the scores between 0 and 100"<<endl;
                cout<<"Enter the Subject scores : ";
                j = 0;
            }
        }
        obj.scores = scores;
        v.push_back(obj);
    }
    Menu(v);
}

