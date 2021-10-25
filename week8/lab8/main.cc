#include "Student.hh"

int main(){
    // TODO: Fill Your Code 
    // Note: You must solve this problem using array of obejects.
    Student stu[10];

    for(int i = 0; i < 10; i++) {
        int sn, current, n;
        char old;
        std::cin >> sn >> current >> n;
        Student stmp(sn, current, n);
        for(int j = 0; j < n; j++) {
            Grade g;
            std::string tmp;
            double a;
            std::cin >> tmp;
            int p = tmp.find("/");
            if(tmp[0] == 'A') a = 4;
            else if(tmp[0] == 'B') a = 3;
            else if(tmp[0] == 'C') a = 2;
            else if(tmp[0] == 'D') a = 1;
            else if(tmp[0] == 'F') a = 0;
            if(tmp[p-1] == '+') a += 0.5;

            g.a = a;
            g.b = tmp[p+1] - '0';
            stmp.put_grade(g);
        }
        std::cin >> old;
        stmp.put_old(old == 'T');
        stu[i] = stmp;
    }

    for(int i = 0; i < 10; i++)
        stu[i].check();
    
    return 0;
}
