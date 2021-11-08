#include "base.hh"

// TODO: inherits the class BaseArray
class CircularQueue : public BaseArray{
public:
    CircularQueue(int _capacity) : BaseArray(_capacity), rear(-1), front(-1){} //TODO: Complete the construtor.
    ~CircularQueue(){ std::cout << "circular_queue deallocated" << std::endl; }

public:
    void enqueue(int n);   
    int dequeue();  
    bool isEmpty();
    bool isFull();

private:
    int rear;
    int front;
};

