#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int n;
    string line;

    cin >> n;
    //-----------------------------------------------------------//
    // TODO: Fill your code
    cin.ignore();
    for(int i = 0; i < n; i++) {
        getline(cin, line);
        if(line[0] >= 'A' && line[0] <= 'Z') line[0];
        else line[0] = line[0] - 32;
        cout << line << endl;
    }
    //-----------------------------------------------------------//
    

 
}
