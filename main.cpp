// asgn BY Jonathan Jackson,  CSCI 2170-001, Due: Midnight, 09/19/2017
// PROGRAM ID:  average.cpp / The Average Problem
// AUTHOR:  Jonathan Jackson
// INSTALLATION:  MTSU
// REMARKS:  This program dus stuf gud.

/* use ../<file> to run successfully, something with my file structure */

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void OpenFile(ifstream &myIn);
void ComputeStatistics(ifstream &myIn, int &counter, int &numLargest, int &numSmallest, int &accumulator, float &avg);
void DisplayResults(int &counter, int &numLargest, int &numSmallest, int &accumulator);

int main()
{
	ifstream myIn;   // contains file object
	int counter = 0; // counts how many numbers are added together
	int accumulator = 0; // the sum of all numbers
    int numLargest = 0;  // constains largest number in set
	int numSmallest = 0; // contains smallest number in set
    float avg = 0.0;
	
	OpenFile(myIn);
	ComputeStatistics(myIn, counter, numLargest, numSmallest, accumulator, avg);
	DisplayResults(counter, numLargest, numSmallest, accumulator);
    
	return 0;
}

// User Defined Functions
void OpenFile(ifstream &myIn) { 
    
    string filename; // contains file to read
    
	//Prompt User for file to open
	cout << "Please enter the filename to read: ";
	cin >> filename;
		
	// open file
	myIn.open(filename.c_str());
	
	// confirm file opens successfully
	assert(myIn);
}

void ComputeStatistics(ifstream &myIn, int &counter, int &numLargest, int &numSmallest, int &accumulator, float &avg) {
	int currentNum;
		
	while(myIn >> currentNum) {
		if (currentNum > numLargest) {
			numLargest = currentNum;
		} else if (currentNum < numSmallest) {
			numSmallest = currentNum;
		}
		
        ++counter;
		cout << currentNum << endl;
		accumulator += currentNum;
	}
    
    //Calculate average
    avg = (accumulator / counter) + (accumulator % counter);
    cout << "Avg is " << avg;
    
}

void DisplayResults(int &counter, int &numLargest, int &numSmallest, int &accumulator) {
    cout << "Total " << counter << " numbers.\n"
         << "The largest number is " << numLargest
         << ", and the smallest number is " << numSmallest << ".\n";
}