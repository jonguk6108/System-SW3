//5.constructor
//조금 더 복잡한 문제로 예를 들도록 한다.
//이제는, 학생 한명의 성적만을 관리하는 것이 아닌, 학생 여러명을 관리하려고 한다.
//class의 구성은 이전과 같다.
//main에서는 가장 처음으로 학생 인원수(N)를 받고. 입력 순서대로, 학생들의 학생들의 번호가 지정된다.(0~N-1)
//인원수를 받은 이후 순차적으로  학생들의 이름, lab 성적과, hw 성적을 입력받는다.
//이때 생성자를 이용하도록 한다.
//N명 모두 입력받은 후, 학생 한명의 번호를 입력받아 이름과 성적을 출력하도록 한다.

//6.default constructor / multiple constructor 
//수강 정정기간에 새로운 학생이 두명 더 들어와서 main함수에 new_student1,2를 추가 한다.
//이때 new student1은 default constructor를 사용하여 추가한다.
//또한, new student2는 multiple constructor를 사용하여 이름만을 인자로 받도록 하여 추가한다.

//7. ADT(abstract data type)
//지금까지 한 내용들을 ADT를 사용하여 구현하도록 한다.
//resolution operation"::"를 통해 함수들의 내용을 Student class 밖으로 뺀다. 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student{
    public:
        Student(string name_, int lab_, int hw_);
        Student(string name_);
        void print_grade();
        int get_lab();
        int get_hw();
        string get_name();
        void set_lab(int lab_);
        void set_hw(int hw_);
        void set_name(string name_);
    private:
        string name;
        int lab;
        int hw;
};
int main(){
    int total_num, printed_num;
    string name;
    vector<Student> students;

    int lab, hw;

    cin >> total_num;
    for(int i = 0; i < total_num; i++) {
        cin >> name >> lab >> hw;
        Student student(name, lab, hw);
        students.push_back(student);
    }
    cin >> printed_num;
    students[printed_num].print_grade();

    Student new_student2("hong");

    new_student1.print_grade();
    new_student2.print_grade();
}
Student::Student(string name_, int lab_, int hw_){name =name_; lab = lab_; hw = hw_;}
Student::Student(string name_){name = name_; lab = 0; hw = 0;}
void Student::print_grade(){cout<<name<<" "<<lab<<" "<<hw<<endl;}
int Student::get_lab(){return lab;}
int Student::get_hw(){return hw;}
string Student::get_name(){return name;}
void Student::set_lab(int lab_){lab = lab_;}
void Student::set_hw(int hw_){hw = hw_;}
void Student::set_name(string name_){name = name_;}
