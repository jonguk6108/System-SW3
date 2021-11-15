#include "hashtable.cc"
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
}
