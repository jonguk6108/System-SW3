/* ***************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : main.cc
 * - File Type : c++ source code
 * - File Version(Last Update Date) : 1.0
 * - Date : Oct. 26, 2021.
 * - Description : This code is provided main function code for SSE2034-41(SKKU, 2021) class Practice10.
 *                 Do not modify this code! Do not distribute this code without permission.
 * **************************************************************************************************/

#include <iostream>

#ifdef QUEUE
#include "queue.h"
#endif

#ifdef P_QUEUE
#include "priorityqueue.h"
#endif

#include <vector>
#include <string>

int main (int argc, char *argv[]) {

    using namespace std;

    vector<int> inputs;

    for (int i=1; i<argc; i++) {
        inputs.push_back(stoi(argv[i]));
    }

#ifdef QUEUE
    Queue::structure queue = Queue::structure();
#endif
#ifdef P_QUEUE
    PriorityQueue::structure priority_queue = PriorityQueue::structure();
#endif

    cout << "Push Inputs : ";
    for (auto input : inputs) {

        cout << input << " ";

#ifdef QUEUE
        queue.push(input);
#endif
#ifdef P_QUEUE
        priority_queue.push(input);
#endif
    }

    cout << endl;

#ifdef QUEUE
    cout << "Queue Pop : ";

    while (!queue.empty()) {
        cout << queue.pop() << " ";
    }

    cout << endl;
#endif

#ifdef P_QUEUE
    cout << "Priority Queue Pop : ";

    while (!priority_queue.empty()) {
        cout << priority_queue.pop() << " ";
    }

    cout << endl;
#endif

    return 0;
}
