// asgn BY student name,  CSCI ####-sec, Due: mm/dd/yyyy
// PROGRAM ID:  file-name.cpp / one-line description
// AUTHOR:  student name
// INSTALLATION:  MTSU
// REMARKS:  short description

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>
using namespace std;

struct Hits {
	int rank;
	string artistName;
	string songTitle;
	int year;
};

void ReadData(ifstream &myIn, Hits arr[], int &noi);

void DisplayArray(Hits arr[],int noi);

const int SIZE = 500;

int main()
{
	Hits arr[SIZE]; // ARRAY
	ifstream myIn; // input file stream
	int noi=0; // number of items in ARRAY
	
	ReadData(myIn,arr,noi);
	
	DisplayArray(arr,noi);
	
	return 0;
}

void ReadData(ifstream &myIn, Hits arr[], int &noi) {
	
    myIn.open("topsongs.dat");
    assert(myIn);
	
    while(myIn >> arr[0].rank) {
        myIn.ignore(100,'\n');
        getline(myIn,arr[0].artistName);
        getline(myIn,arr[0].songTitle);
        myIn >> arr[0].year;
        myIn.ignore(100,'\n');
        noi++;
    }
    
    myIn.close();
    
}

void DisplayArray(Hits arr[],int noi) {
    
    //int searchedLocation = 0;
    
//add $this     // display searched-for artist + data
    //cout << "Here are the songs by " << arr[searchedLocation].artistName << endl;
    
    // display column HEADERS
    cout << left << setw(30) << "Title" << setw(6) << "Rank" << setw(4) << "Year\n";
    
    //cout << arr[noi].rank << ' ' << arr[noi].artist << ' ' << arr[0].song << ' ' << arr[noi].year << endl;
    
    for (int i=0; i<3; i++) {
        cout << setw(30) << arr[i].songTitle << setw(6) << arr[i].rank << setw(4) << arr[i].year << endl;
    }
}
