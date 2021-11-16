#include "hashtable.cc"
int main()
{
    int key[6] = {2018312727, 2017612789, 2019342781, 2021110112, 2121131543, 2021473489};
    int Phone_number[6] = {73549732,75311549,12314987,19852342,31171398,18967512};

    char Grade[6] = {'A', 'C', 'F', 'D', 'B', 'E'};
    double Score[6] = {99.9, 60.1, 10.1, 40.1, 80.1, 30.1};

    int size = sizeof(key) / sizeof(key[0]);

    HashTable<int> h(size);
    for (int i = 0; i < 6; i++)
        h.insertItem(key[i], Phone_number[i]);
    //h.deleteItem(2018312727,73549732);
    h.displayHash(); 

    
    HashTable<char> h2(size);
    for (int i = 0; i < 6; i++)
        h2.insertItem(key[i], Grade[i]);
    h2.displayHash(); 

    HashTable<double> h3(size);
    for (int i = 0; i < 6; i++)
        h3.insertItem(key[i], Score[i]);
    h3.displayHash(); 
}
