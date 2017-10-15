// asgn BY Jonathan Jackson,  CSCI 2170-001, Due: Midnight, Thursday, 10/19/2017
// PROGRAM ID:  topsongs.cpp / Top Billboard SongsType Program
// AUTHOR:  Jonathan Jackson
// INSTALLATION:  MTSU
// REMARKS:  short description

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>

using namespace std;

struct SongsType {
	int rank;
	string artistName;
	string songTitle;
	int year;
};

void ReadData(ifstream &myIn, SongsType arr[], int &noi);
void DisplayMenu(int &choice);
void PrintByArtist(SongsType arr[],int noi,string targetName);
void PrintByYear(SongsType arr[],int noi,int targetYear);
void AddSong(SongsType arr[],int &noi);
void DeleteSong(SongsType arr[],int &noi);
int LinearSearch(SongsType arr[],int noi,string targetSong);
void DisplayArray(SongsType arr[],int noi);

const int SIZE = 500;

int main()
{
    SongsType arr[SIZE]; // ARRAY
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
        
        } else if (choice == 3) {
            AddSong(arr,noi);
        
        } else if (choice == 4) {
            DeleteSong(arr,noi);
        }
        
    }
    
    return 0;
}


// Open DATA file, read DATA in to ARRAY objects, close file
void ReadData(ifstream &myIn, SongsType arr[], int &noi) {

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
    cout << right << setw(52) << "Billboard Top Song (2012-2015) Management"
         << endl << endl
         << setw(49) << "Please select from the following menu choices:"
         << endl << endl
         << left << setw(11) << ' ' << "1.  Look up top hits by artist\n"
         << setw(11) << ' ' << "2.  Look up top hits by year\n"
         << setw(11) << ' ' << "3.  Add a new song\n"
         << setw(11) << ' ' << "4.  Delete an existing song\n"
         << setw(11) << ' ' << "5.  Exit"
         << endl << endl;
    
    cout << setw(11) << ' ' << "Enter your choice: ";
    cin >> choice; // get Ue
    cin.ignore(100,'\n');
}

void PrintByArtist(SongsType arr[],int noi,string targetName) {
    
    SongsType ArtistSongsType[SIZE]; // new temporary ARRAY for found hits
    int counter = 0;  // numOfItems for temp ARRAY
    
    // go through FULL_ARRAY, if artistName matches,
    // add to the new/2ndary ARRAY and +1 to the 2nd ARRAY counter
    for (int i=0; i<noi ; i++) {
        if (targetName == arr[i].artistName) {
            ArtistSongsType[counter] = arr[i];
            counter++;
        }
    }
    
    // if no hits were found by this artist, print ERROR message
    if (counter == 0) {
        cout << "ERROR: " << targetName << " hasn't had any hits in the past 4 years.\n";
    
    // otherwise, print title, rank & year in table format
    } else {    
        //Display ARTIST HEADER
        cout << "Here are the songs by " << targetName << endl << endl;
        //Display COLUMN HEADERS
        cout << left << setw(30) << "Title" << setw(6) << "Rank" << setw(4) << "Year\n";
    
        for (int i=0; i<counter; i++) {
            cout << setw(30) << ArtistSongsType[i].songTitle << setw(6) << ArtistSongsType[i].rank << setw(4) << ArtistSongsType[i].year << endl;
        }
    }
    
    cout << endl << endl;
    setw(0);
}

void PrintByYear(SongsType arr[],int noi, int targetYear) {
    
    for (int i=0; i<noi ; i++) {
        if (targetYear == arr[i].year){
            cout << arr[i].songTitle << endl;
        }
    }
    cout << endl << endl;
}

void AddSong(SongsType arr[],int &noi) {
    SongsType newHit;
    
    cout << "Enter the new Song Title: ";
    getline(cin,newHit.songTitle);
    cout << "Enter the Artist Name: ";
    getline(cin,newHit.artistName);
    cout << "Enter the Song Rank: ";
    cin >> newHit.rank;
    cin.ignore(100,'\n');
    cout << "Enter the Release Year: ";
    cin >> newHit.year;
    cin.ignore(100,'\n');
    
    arr[noi] = newHit;
    noi++;
}

void DeleteSong(SongsType arr[],int &noi) {
    string targetSong;
    int loc;
    
    cout << "Enter the Song Title to be deleted: ";
    getline(cin,targetSong);
    
    loc = LinearSearch(arr,noi,targetSong);
    cout << "noi is " << noi << endl;
    
    if (loc == -1) {
        cout << "ERROR: No matching Song Title was found.";
    } else {
        for (int i=loc; i<noi; i++) {
            arr[i] = arr[i+1];
        }
        
    }
    noi--;
    cout << "NEW noi is " << noi << endl;
}

int LinearSearch(SongsType arr[],int noi,string targetSong) {
    for (int i = 0; i < noi; i++) {
        if (arr[i].songTitle == targetSong)
            return i;
    }
    return -1;
}

//DEBUGGING FUNCTION
void DisplayArray(SongsType arr[],int noi) {
    
    // display column HEADERS
    cout << left << setw(30) << "Title" << setw(6) << "Rank" << setw(4) << "Year\n";
    
    //cout << arr[noi].rank << ' ' << arr[noi].artist << ' ' << arr[0].song << ' ' << arr[noi].year << endl;
    
    for (int i=0; i<12; i++) {
        cout << setw(30) << arr[i].songTitle << setw(6) << arr[i].rank << setw(4) << arr[i].year << endl;
    }
}
