#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>

class PriorityQueue {
    private:
    std::vector <double> data;

    void sort();

    public:

    PriorityQueue();

    friend bool is_ahead(PriorityQueue queue, size_t idx1, size_t idx2);

    void push(double element);
    double front();
    double pop();

};

#endif
