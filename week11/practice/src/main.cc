#include "myqueue.hh"
#include "mystack.hh"

int main() {

/*
 * Practice1 - Implementing MyQueue class.
 */
#ifdef MYQUEUE
    MyQueue mQ(100);
    int n;
    std::cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
    for(int i=0; i<5; i++){
        std::cin >> n;
        mQ.enqueue(n); // 큐에 삽입    
    }

    std::cout << "큐의 원소를 순서대로 제거하여 출력한다 >> ";  
    for(int i=0; i<5; i++){
        std::cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력   
    }
    std::cout << std::endl;
#endif


/*
 * Practice2 - Implementing MyStack class.
 */
#ifdef MYSTACK   
    MyStack mS(100);
    int n;
    std::cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
    for(int i=0; i<5; i++){
        std::cin >> n;
        mS.push(n); // 큐에 삽입    
    }

    std::cout << "큐의 원소를 순서대로 제거하여 출력한다 >> ";  
    for(int i=0; i<5; i++){
        std::cout << mS.pop() << ' '; // 큐에서 제거하여 출력   
    }
    std::cout << std::endl;
#endif


/*
 * Practice3 - Polymorphism
 */
#ifdef POLYMORPHISM   
    BaseArray* ba = new MyQueue(100);

    int n;
    std::cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
    for(int i=0; i<5; i++){
        std::cin >> n;
        ba->enqueue(n); // 큐에 삽입
    }

    std::cout << "큐의 원소들을 차례대로 제거하며 큐의 정보들을 출력>> " << std::endl;    
    for(int i=0; i<5; i++){
        std::cout << ba->dequeue() << "(size: " << ba->getSize() <<") " ; // 큐에서 제거하여 출력  
        ba->printLoc();
    }
    std::cout << std::endl;

#endif



/*
 * Practice4 - Virtual Destructor
 */
#ifdef MEMORYLEAKAGE   
    BaseArray* ba = new MyQueue(100);
    delete ba;
#endif




}




