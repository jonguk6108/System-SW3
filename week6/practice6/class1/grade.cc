//class1 실습 목표
//class를 정의해보고 접근 지정자에 대해 알아본다.

//1.class 정의 및 public 접근 지정자
//class로 정의된 student변수의 lab과 grade를 print하도록 한다.
// 첫 번째로 public member function, variable만을 가지고 있는 Student class를 정의하고 사용해본다.
// Student class는 member function으로 print_grade함수를 갖는다.
// Student class는 member variable으로 lab과 hw을 갖는다.
// main 함수에서는 input을 받고, class 변수를 선언한다.
// '.'을 통해 class의 멤버 변수에 접근하여 값을 대입한다.
// Student class의 print_score() 함수를 통해, 값을 출력한다.
// main function에서 '.'을 통해 멤버 변수를 직접 가져와 cout을 통해 출력한다.
// 이때, 처음 선언이 잘 못 되어 있는 부분이 있는데, 이 부분을 수정하여라.
//
// 2. class 정의 및 private 접근 지정자
// 맴버 변수를 private으로 만들어 다시 컴파일하여 실행해본다.
//
// 3. 접근 지정자가 없을 경우
// 접근 지정자가 없을 경우 어떤 접근 지정자가 default로 되어 있는지 확인해본다.
//
// 4. access/mutator function
// 변수를 private로 하고, 함수를 public으로 만든다.
// 그 후, access function과 mutator function을 사용하여, main함수에서도 class의 private 값을 획득 및 변경할 수 있도혹 한다.

#include<iostream>
using namespace std;
class Student {
    public :
        void print_grade() {
            cout << "(class)" << lab << " " << hw << endl;
        }
        int get_lab() {
            return lab;
        }
        int get_hw() {
            return hw;
        }
        void set_lab(int lab_) {
            lab = lab_;
        }
        void set_hw(int hw_) {
            hw = hw_;
        }
    private :
        int lab;
        int hw;
};
int main(){
    int lab, hw;
    cin >> lab >> hw;
    Student student;
    student.set_lab(lab);
    student.set_hw(hw);
    student.print_grade();
    cout << "(main)" << student.get_lab() << " " << student.get_hw() << endl;
}

