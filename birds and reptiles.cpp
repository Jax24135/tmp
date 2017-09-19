// not repeated before or after itself
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string test1, test2, test3;
    int n = 0;
    
    cout << "enter next1: ";
    cin >> test1;

    while (test1 != "xxxxx") {
        cout << "test1 is " << test1 << endl;
        if (test1 != test2) {
            ++n;
        }
        cout << "enter test2: ";
        cin >> test2;
        if (test2 != "xxxxx") {
            cout << "test2 is " << test2 << endl;
            if (test1 != test2){
                ++n;
                cout << "n is " << n << ", enter next test1: " << endl;
            }
        cin >> test1;
        }
    }
    
    cout << n;
}
