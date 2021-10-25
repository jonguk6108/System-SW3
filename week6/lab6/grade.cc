#include<iostream>
#include<string>
#include<vector>
using namespace std;

int weight[4];

class Student{
    public:
        Student(string name_);
        string print_name();
        void setlab(int weekN_, int score_);
        void sethw(int weekN_, int score_);
        void setprj(int score_);
        void setexam(int score_);
        void setscoreweight(int* weight_);
        void printscore();
        void printscoredetail();


    private:
        string name;
        int lab[10];
        int hw[10];
        int prj, exam;
};
int main(){
    string oper;
    vector<Student> students;
    string name;
    int weekN, score;
    int first = 0, i;
    for(i = 0; i < 4; i++)
        weight[i] = i+1;

    while(1) {
        cin >> oper;
        if(oper == "exit") break;
        if(oper == "add") {
            string name;
            cin >> name;
            Student student(name);
            students.push_back(student);
        }
        else if(oper == "setlab") {
            cin >> name >> weekN >> score;
            for(i = 0; i < students.size(); i++)
                if(students[i].print_name() == name)
                    break;
            students[i].setlab(weekN, score);
        }
        else if(oper == "sethw") {
            cin >> name >> weekN >> score;
            for(i = 0; i < students.size(); i++)
                if(students[i].print_name() == name)
                    break;
            students[i].sethw(weekN, score);
            
        }
        else if(oper == "setprj") {
            cin >> name >> score;
            for(i = 0; i < students.size(); i++)
                if(students[i].print_name() == name)
                    break;
            students[i].setprj(score);
        }
        else if(oper == "setexam") {
            cin >> name >> score;
            for(i = 0; i < students.size(); i++)
                if(students[i].print_name() == name)
                    break;
            students[i].setexam(score);
        }
        else if(oper == "setscoreweight") {
            cin >> weight[0] >> weight[1] >> weight[2] >> weight[3];
        }
        else if(oper == "printscore") {
            if(first != 0) cout << " ";
            first++;
            cin >> name;
            for(i = 0; i < students.size(); i++)
                if(students[i].print_name() == name)
                    break;
            students[i].printscore();
        }
        else if(oper == "printscoredetail") {
            if(first != 0) cout << " ";
            first++;
            cin >> name;
            for(i = 0; i < students.size(); i++)
                if(students[i].print_name() == name)
                    break;
            students[i].printscoredetail();
        }
    }
}

Student::Student(string name_) {
    name = name_; 
    for(int i = 0; i < 10; i++) {
        lab[i] = 0;
        hw[i] = 0;
    }
    for(int i = 0; i < 4; i++)
        weight[i] = i + 1;
    prj = 0;
    exam = 0;
}
string Student::print_name() {return name;}
void Student::setlab(int weekN_, int score_) {lab[weekN_] = score_;}
void Student::sethw(int weekN_, int score_) {hw[weekN_] = score_;}
void Student::setprj(int score_) {prj = score_;}
void Student::setexam(int score_) {exam = score_;}
void Student::printscore() {
    int ans = 0;
    for(int i = 0; i < 10; i++)
        ans += lab[i]*weight[0];
    for(int i = 0; i < 10; i++)
        ans += hw[i]*weight[1];
    ans += prj*weight[2];
    ans += exam*weight[3];
    cout << ans;
}
void Student::printscoredetail() {
    for(int i = 0; i < 10; i++)
        cout << lab[i] << " ";
    for(int i = 0; i < 10; i++)
        cout << hw[i] << " ";
    cout << prj << " " << exam;
}
