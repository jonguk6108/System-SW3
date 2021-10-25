#include <iostream>
#include <string>
#include <vector>

struct Grade {
    double a;
    int b;
};

class Student{

public: 
    Student() : sn(0), current(0), n(0) {}
    Student(int sn_, int current_, int n_) : sn(sn_), current(current_), n(n_){}
    void put_grade(Grade g_);
    void put_old(bool old_);
    void check();
    bool check_tmp();
    

private:
    int sn;
    int current;
    int n;
    bool old;
    std::vector<Grade>g;

};

