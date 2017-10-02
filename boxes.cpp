#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void ReadData(string[], int[],int&);

const int ARRAY_SIZE = 10;

int main() {
    
    string classNames[ARRAY_SIZE];  // class names ARRAY
    int boxes[ARRAY_SIZE];          // boxes sold ARRAY
    int numOfItems = 0;             //should be same for both arrays

    ReadData(classNames, boxes, numOfItems);
    
    return 0;
}


void ReadData(string classNames, int boxes, int &i) {
    
    ifstream myIn; // declare file stream object
    
    myIn.open("boxes.dat"); // open file
    assert(myIn);          // confirm file opens
    
    if (myIn >> !"") {
        myIn >> classNames[i] >> boxes[i];
    }
    
    for (int j=0; j<=i; j++) {
        cout << "classnames array is: " << classNames[j] << endl;
        cout << "boxes array is: " << boxes[j] << endl;
    }
    
}
