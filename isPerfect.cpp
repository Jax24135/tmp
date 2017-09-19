#include <iostream>
#include <cstring>
using namespace std;

void IsPerfect(int &test);

int main()
{
    int test = 10000;
    
    cout << "IsPerfect function..." << endl;
    IsPerfect(test);

    return 0;
}


void IsPerfect(int &test) {
    int accumulator;
       
    for(int i = 1; i < test; i++) {
        accumulator = 0;
      
        for (int j=1 ; j<i ; j++) {
            if (i % j == 0) {
                //cout << j << ",";
                accumulator = accumulator + j;
            }
                        
        }
        
        if (accumulator == i) {
            cout << i << " is equal to " << accumulator << ", and a perfect number." << endl;
        }
              
    }
}
