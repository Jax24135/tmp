#include <iostream>
#include <string>
using namespace std;

void IsPerfect(int &test);

int main()
{
    int test = 30;
    
    cout << "IsPerfect function..." << endl;
    IsPerfect(test);

    return 0;
}

void IsPerfect(int &test) {
    // run a test through main-testing #s
    for(int i = 23; i < 25; i++) {
        if (accumulator == i) {
            cout << i << 
        }
        
        int accumulator = 0;
        for (int j=1; j<i; j++) {     
            if (i%j == 0) {
                cout << "i is " << i << ", j is " << j << endl;
                accumulator += j;
            
                if (accumulator == i) {
                    cout << i << " is a perfect#." << endl;
                }
            }
        }
    } 
}
