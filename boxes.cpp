/*
 * PROGRAMMER: Jonathan Jackson
 * Assignment: Open Lab Assignment 3
 * Class: CSCI 2170, Section 1
 * Course Instructor: Dr. Li
 * Due Date: Midnight, Thursday, 10/05/2017
 * Description:
 * This program reads in data file into 2 arrays: NAMES and BOXES sold
 * If the NAME is already in the 1st ARRAY, add BOXES to ARRAY-2's matching location.
 * 
 * Otherwise, add the new NAME and BOXES to a new cell location.
 * 
 * When finished, print results to screen in table format and show winner of
 * "highest boxes sold" contest. Also sorted for XtraCredit.
 */ 


#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>

using namespace std;


void ReadData(ifstream&,string[],int[],int&);

int LinearSearch(string[],string,int&);

int FindWinner(string[],int[],int);

void DisplayResults(string[],int[],int,int);

void SelectionSort(string[],int[],int);

const int SIZE = 20; // set ARRAY size

int main() {
    
    ifstream myIn;              // contains file object for reading
    string classNames[SIZE];    // ARRAY for the different classes
    int boxes[SIZE];            // ARRAY for boxes sold
    int numOfItems=0;           // number of items in ARRAYs (should be the same)
    int highestLoc;     	// array location of highest boxes sold
    
    // Pass the file stream, classNames ARRAY, boxes ARRAY & numberOfItems to function
    ReadData(myIn,classNames,boxes, numOfItems);
    
    // Sort boxes[] && classNames[] into ascending numeric order
    SelectionSort(classNames,boxes,numOfItems);
	
    // Finds the ARRAY location of the highest number of boxes
    highestLoc = FindWinner(classNames, boxes, numOfItems);
  
    // Displays the results in a table format	
    DisplayResults(classNames, boxes,numOfItems,highestLoc);
     
    return 0; // Exit program cleanly
}

// User-Defined Functions

// Open/close and read in a pre-existing data file.
// Use LinearSearch() to determine if NAME is already in 1st-ARRAY
void ReadData(ifstream &myIn,string classNames[], int boxes[],int &numOfItems){
    
    string tmpClass; // temporary holder for evaluating class names
    int tmpBoxes;    // temporary holder for evaluating where to store sales
    int result;      // holds ARRAY_location for new or existing classNames
        
    myIn.open("boxes.dat"); // open specified file location
    assert(myIn);           // confirm file open OK

    // read in each line from file(name+' '+sales) and read into placeholders
    // pass on to LinearSearch() to see if className already exists (>=0)
    //
    // if not found in existing classNames[], make a new cell for name+boxes
    // and add 1 to number of existing items (numOfItems)
    while(myIn >> tmpClass >> tmpBoxes) {
		
		// LinearSearch() returns either an -1 or greater value
        result = LinearSearch(classNames, tmpClass, numOfItems);
        			
        // if 0 or greater, it's already in the ARRAY, so just add the tmpBoxes to existing location
        if (result > -1) {
            boxes[result] += tmpBoxes;
			
        // otherwise, add a new 'cell' to the current array and put new className && new boxes there
        } else {
            classNames[numOfItems] = tmpClass;
            boxes[numOfItems] = tmpBoxes;
            numOfItems++;
        }		
    }
    
    myIn.close();   // close file
}

// Search the 1st-ARRAY for a name, if existing - return ARRAY location
// otherwise, return -1 as sentinel value to create new location and increase numOfItems in both ARRAYS
int LinearSearch(string classNames[],string tmpClass,int &numOfItems) {

	// Search 1st array for tmpClass name
    for(int i=0;i<numOfItems;i++) {
        if (classNames[i] == tmpClass) {
            return i;
        }
    }
    
    // gone through whole array... time to add a new cell
    return -1;
}

// compare BOXES ARRAY values to find the highest BOXES sold
// return the ARRAY location of the highest BOXES sold
int FindWinner(string classNames[], int boxes[], int numOfItems) {
	
	int highest = 0;	// holds the number of boxes, used to find highest number
	int loc = -1;		// keeps the ARRAY location of highest BOXES sold
	
	// Go through the BOXES ARRAY comparing values and holding the location of
	// the highest BOXES sold.
	for(int i=0; i<numOfItems;i++) {
		if (boxes[i] > highest) {
			highest = boxes[i];
			loc = i;
		}
	}
	return loc;	// return highest BOXES ARRAY location
}

// Show the results of the BOXES contest in table form.
// Print the winner w/ how many boxes sold.
void DisplayResults(string classNames[], int boxes[], int numOfItems, int highestLoc) {
	
	// Print table header
	cout << "The final results are:\n";
		
	// Print contents of each array side-by-side in table format.
	for(int i=0; i<numOfItems; i++) {
		cout << left << setw(18) << classNames[i] << setw(4) << boxes[i] << endl;
	}
	
	// Print winner in final form.
	cout << endl << "The winner is " << classNames[highestLoc] << " sold " << boxes[highestLoc] << " boxes.\n";
}

// This function takes an established ARRAY and sorts it into numeric order based on BOXES sold
// also moves matching classNames[] to same order
void SelectionSort(string classNames[],int boxes[],int numOfItems) {
    int i;              //sets the outer loop counter 
    int j;              // move through ARRY for $lowest comparison
    int smallestLoc;    // stores the ARRAY location of the smallest BOXES number
    int lowest;         // stores the lowest number of boxes sold (works with 'j')
    int tmpBoxes;       // temporary holder for switching 'i' for lowest boxes sold and vice versa
    string tmpNames;    // temporary holder for switching 'i' for matching className and vice versa
    
    // use 'i' to move through outer ARRAY, once this is set by the "!=i" logic
    // keep moving through.
    for (i=0 ; i<numOfItems ; i++) {
        smallestLoc = i;
        
        
        // start +1 past the current smallestLocation in search of a number lower
        // than itself.
        // If found, save the location for future comparisons in this iteration loop
        for(j=i+1 ; j < numOfItems;j++) {
            if (boxes[j] < boxes[smallestLoc]) {
                smallestLoc = j;
            }
        }
        
        // after finding the lowest possible ARRAY location, save current 'i' value to a placeholder
        // move the lowest location to 'i' value (moves on past there)
        // save the 'i' location back to where the smallestLocation WAS.
        
        if (smallestLoc != i) {
            tmpBoxes = boxes[i];
            tmpNames = classNames[i];
            boxes[i] = boxes[smallestLoc];
            classNames[i] = classNames[smallestLoc];
            boxes[smallestLoc] = tmpBoxes;
            classNames[smallestLoc] = tmpNames;
        }
    }
}
