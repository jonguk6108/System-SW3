#include "base.hh"

// TODO: inherits the class BaseArray
class CircularQueue {
public:
    CircularQueue(int _capacity) {} //TODO: Complete the construtor.
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

