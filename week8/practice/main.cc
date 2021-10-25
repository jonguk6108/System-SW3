#include <iostream>
#include <algorithm>

class Point{

public:
    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {}
    bool operator > (Point rhs);
    bool operator < (Point rhs) {return !((*this) > rhs);}
    void print() { std::cout << x << " " << y<< std::endl; }
 
private:
    int x, y;
};


int main(){
    Point points[5];
    for(int i = 0; i < 5; i++) {
        int x, y;
        std::cin >> x >> y;
        points[i] = Point(x, y);
    }
    /*
    Point tmp;
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 5; j++)
            if(points[i] > points[j] ) {
                tmp = points[j];
                points[j] = points[i];
                points[i] = tmp;
            }
    */
    std::sort(std::begin(points), std::end(points));
    for(int i = 0; i < 5; i++) points[i].print();
}

bool Point::operator > (Point rhs) {
    if(y > rhs.y) return 1;
    if(rhs.y == y && x > rhs.x) return 1;
    return 0;
}
