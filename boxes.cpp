#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

void ReadData(ifstream&, string[], int[],int&);
int LinearSearch(string[], string, int);

const int SIZE = 20;

int main() {
    
    ifstream myIn;              // contains file object for reading
    string classNames[SIZE];    // ARRAY for the different classes
    int boxes[SIZE];            // ARRAY for boxes sold
    int noi=0;                  // number of items in ARRAYs (should be the same)
    
	// Pass the file stream, classNames ARRAY, boxes ARRAY & numberOfItems to function
    ReadData(myIn,classNames,boxes, noi);
    
    // print out ARRAY values
    for(int j=0 ; j<noi;j++) {
        cout << "class is " << classNames[j] << " sales is " << boxes[j] << endl;
    }
     
    return 0;
}


// User-Defined Functions

void ReadData(ifstream &myIn,string classNames[], int boxes[],int &noi){
    
    string tmpClass; // temporary holder for evaluating class names
    int tmpBoxes;    // temporary holder for evaluating where to store sales
    int result;      // holds ARRAY_location for new or existing classNames
        
    myIn.open("boxes.txt"); // open specified file location
    assert(myIn);           // confirm file open OK


    // set first className + Box sales to '0' in both ARRAYs
    // add 1 to number of exisiting items in each array (noi)
    //myIn >> classNames[noi] >> boxes[noi];
	//noi++;

    // read in each line from file(name+' '+sales) and read into placeholders
    // pass on to LinearSearch() to see if className already exists (>=0)
    //
    // if not found in existing classNames[], make a new cell for name+boxes
    // and add 1 to number of existing items (noi)
    
	//int accum=0;
    while(myIn >> tmpClass >> tmpBoxes) {
		
		
		//debugging confirms HuskyPanda numbers; initialize "int accum=0" before WHILE loop
		//if (tmpClass == "Husky") {
		//	accum += tmpBoxes;
		//	cout << "Husky name with: " << tmpBoxes << " added is " << accum << endl; }
		
 		/*Resume real PRGM*/
		
		// LinearSearch() returns either an -1 or greater value
        result = LinearSearch(classNames, tmpClass, noi);
        			
        // if 0 or greater, it's already in the ARRAY, so just add the tmpBoxes to existing location
        if (result > -1) {
            boxes[result] += tmpBoxes;
			
        // otherwise, add a new 'cell' to the current array and put new className && new boxes there
        } else {
            classNames[noi] = tmpClass;
            boxes[noi] = tmpBoxes;
            noi++;
        }
       
        
        //if (classNames[result] == "Husky") {
        //    cout << "className is " << tmpClass << ", sales is " << tmpBoxes
        //         << ", and total sales is " << boxes[result] << endl; }
		
		
    }
    
    myIn.close();   // close file stream
}


int LinearSearch(string classNames[],string tmpClass,int noi) {

    for(int i=0;i<noi;i++) {
        if (classNames[i] == tmpClass) {
            return i;
        }
    }
    
    // gone through whole array... time to add a new cell
    return -1;
}
