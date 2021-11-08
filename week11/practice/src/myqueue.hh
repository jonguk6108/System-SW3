#include "base.hh"

class MyQueue{
public:
    MyQueue(int _capacity) : practice4(new int[100]){}
    ~MyQueue(){ 
        delete[] practice4; 
        std::cout <<"MyQueue의 practice4 해제" << std::endl;
    }

public:
    void enqueue(int n) {
        // TODO: Fill Your Code Here

    }   
    int dequeue() {
        // TODO: Fill Your Code Here
         
        return 0;
    }

private:
    int rear;
    int front;
    int* practice4;
};


