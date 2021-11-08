#include "base.hh"

class MyQueue : public BaseArray{
public:
    MyQueue(int _capacity) : BaseArray(_capacity), rear(-1), front(-1), practice4(new int[100]){}
    ~MyQueue(){ 
        delete[] practice4; 
        std::cout <<"MyQueue의 practice4 해제" << std::endl;
    }

public:
    void enqueue(int n) override{
        // TODO: Fill Your Code Here
        rear++;
        insert(rear, n);
    }   
    int dequeue() override{
        // TODO: Fill Your Code Here
        front++;
        return get(front);
    }

    int getSize() override{ return rear-front; }
    void printLoc() override{ std::cout << "front: " << front << "rear: " << rear << std::endl; }

private:
    int rear;
    int front;
    int* practice4;
};


