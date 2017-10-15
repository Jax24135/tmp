// asgn BY Jonathan Jackson,  CSCI ####-sec, Due: mm/dd/yyyy
// PROGRAM ID:  file-name.cpp / one-line description
// AUTHOR:  Jonathan Jackson
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
void DisplayMenu(int &choice);
void PrintByArtist(Hits arr[],int noi,string targetName);
void PrintByYear(Hits arr[],int noi,int targetYear);
void DisplayArray(Hits arr[],int noi);

const int SIZE = 500;

int main()
{
    Hits arr[SIZE]; // ARRAY
    ifstream myIn; // input file stream
    int noi=0; // number of items in ARRAY
    int choice = -1;
    string targetName;
    int targetYear;
	
    ReadData(myIn,arr,noi);
        
    while(choice != 5) {
        //always show MENU on iterations
        DisplayMenu(choice);
        
        if (choice == 1) {
            cout << "\nEnter the name of the Artist: ";
            getline(cin,targetName);
            cout << endl;
            PrintByArtist(arr,noi,targetName);
        
        } else if (choice == 2) {
            cout << "\nEnter the Year to list hit songs: ";
            cin >> targetYear;
            cin.ignore(100,'\n');
            cout << endl;
            PrintByYear(arr,noi,targetYear);
        }
            
        /*else if (choice == 3)
            AddSong();
        else if (choice == 4)
            DeleteSong();*/
    }
    
    return 0;
}


// Open DATA file, read DATA in to ARRAY objects, close file
void ReadData(ifstream &myIn, Hits arr[], int &noi) {

    myIn.open("topsongs.dat"); //open DATA file
    assert(myIn);  //confirm file opens
	
    // read the entire file for the order or $rank, $artistName, $songTitle, $year
    while(myIn >> arr[noi].rank) {
        myIn.ignore(100,'\n'); // skip over newLineCHAR at end of cin before next read
        getline(myIn,arr[noi].artistName);
        getline(myIn,arr[noi].songTitle);
        myIn >> arr[noi].year;
        myIn.ignore(100,'\n'); // skip over newLineCHAR at end of cin before next read
        noi++;
    }
    myIn.close(); // close DATA file
}

void DisplayMenu(int &choice) {
    cout << setw(10) << ' ' << setw(0) << "Billboard Top Song (2012-2015) Management"
         << endl << endl
         << setw(2) << ' ' << "Please select from the following menu choices:"
         << endl << endl
         << setw(10) << ' ' << "1.  Look up top hits by artist\n"
         << setw(10) << ' ' << "2.  Look up top hits by year\n"
         << setw(10) << ' ' << "3.  Add a new song\n"
         << setw(10) << ' ' << "4.  Delete an existing song\n"
         << setw(10) << ' ' << "5.  Exit"
         << endl << endl;
    
    cout << setw(10) << ' ' << "Enter your choice: ";
    cin >> choice; // get Ue
    cin.ignore(100,'\n');
}

void PrintByArtist(Hits arr[],int noi,string targetName) {
    
    Hits ArtistHits[SIZE]; // new temporary ARRAY for found hits
    int counter = 0;  // numOfItems for temp ARRAY
    
    // go through FULL_ARRAY, if artistName matches,
    // add to the new/2ndary ARRAY and +1 to the 2nd ARRAY counter
    for (int i=0; i<noi ; i++) {
        if (targetName == arr[i].artistName) {
            ArtistHits[counter] = arr[i];
            counter++;
        }
    }
    
    // if
    
    if (counter == 0) {
        cout << "ERROR: " << targetName << " hasn't had any hits in the past 4 years.\n";
    } else {
        
        //Display ARTIST HEADER
        cout << "Here are the songs by " << targetName << endl << endl;
        //Display COLUMN HEADERS
        cout << left << setw(30) << "Title" << setw(6) << "Rank" << setw(4) << "Year\n";
    
        for (int i=0; i<counter; i++) {
            cout << setw(30) << ArtistHits[i].songTitle << setw(6) << ArtistHits[i].rank << setw(4) << ArtistHits[i].year << endl;
        }
    }
    
    cout << endl << endl;
    setw(0);
}

void PrintByYear(Hits arr[],int noi, int targetYear) {
    
    for (int i=0; i<noi ; i++) {
        if (targetYear == arr[i].year) {
            cout << arr[i].songTitle << endl;
        }
    }
    
    cout << endl << endl;
}

//DEBUGGING FUNCTION
void DisplayArray(Hits arr[],int noi) {
    
    // display column HEADERS
    cout << left << setw(30) << "Title" << setw(6) << "Rank" << setw(4) << "Year\n";
    
    //cout << arr[noi].rank << ' ' << arr[noi].artist << ' ' << arr[0].song << ' ' << arr[noi].year << endl;
    
    for (int i=0; i<12; i++) {
        cout << setw(30) << arr[i].songTitle << setw(6) << arr[i].rank << setw(4) << arr[i].year << endl;
    }
}
