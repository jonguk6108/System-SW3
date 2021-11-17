#include <iostream>
#include <list>
using namespace std;

template<class T>
class HashTable{
    public:
        HashTable(int c);
        void insertItem(int key, T data);
        void deleteItem(int key, T data);
        int checkPrime(int n);
        int getPrime(int n);
        int hashFunction(int key);
        void displayHash();
    private:
        int capacity;
        list<T> *table;
};
template<class T>
HashTable<T>::HashTable(int c){
    // get table size using getprime() and save in capacity
    // allocate dynamic array using list
    int size = getPrime(c);
    this->capacity = size;
    table = new list<T>[capacity];
}
template<class T>
int HashTable<T>::hashFunction(int key){
    return (key%capacity);
}
template<class T>
void HashTable<T>::insertItem(int key, T data){
    int index = hashFunction(key);
    table[index].push_back(data);
    // get table index using hash function
    // and push data into table
}
template<class T>
void HashTable<T>::deleteItem(int key, T data){
    int index = hashFunction(key);

    list<int>::iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++)
        if(*i == data)
            break;
    if(i != table[index].end())
        table[index].erase(i);
    // get table index using hash function
    // search the table where the index matches and
    // deleted if the data matches.
}
template<class T>
int HashTable<T>::checkPrime(int n){
    //this function is called by getprime function
    //to check function parameter is prime number.
    int i;
    if(n == 1 || n == 0)
        return 0;
    for(i = 2; i < n/2; i++)
        if(n%i == 0)
            return 0;
    return 1;
}
template<class T>
int HashTable<T>::getPrime(int n){
    //return the same or larger prime number
    if( n%2 == 0 )
        n++;
    while(!checkPrime(n))
        n += 2;
    return n;
}
template<class T>
void HashTable<T>::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (T x : table[i])
            cout << " --> " << x;
        cout << endl;
    }  
}
/*
int main()
{
    int key[6] = {2018312727, 2017612789, 2019342781, 2021110112, 2121131543, 2021473489};
    int Phone_number[6] = {73549732,75311549,12314987,19852342,31171398,18967512};
    int size = sizeof(key) / sizeof(key[0]);

    HashTable h(size);
    for (int i = 0; i < 6; i++)
        h.insertItem(key[i], Phone_number[i]);

    h.deleteItem(2018312727,73549732);
    h.displayHash(); 
} */
