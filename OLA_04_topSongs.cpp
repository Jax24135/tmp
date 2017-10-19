// asgn BY Jonathan Jackson,  CSCI 2170-001, Due: Midnight, Thursday, 10/19/2017
// PROGRAM ID:  topsongs.cpp / Top Billboard SongsType Program
// AUTHOR:  Jonathan Jackson
// INSTALLATION:  MTSU
// REMARKS:  This program prompts a User via Menu options for searching through
// past hit artists & songs, adding new artist/songs, or deleting songs
// until User chooses to exit the program.
// Base DATA is brought in from existing data file.

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>

using namespace std;

// Custom DataType
struct SongsType {
	int billboardRank; // contains the rank of each song in the year
	string artistName; // contains the artist name
	string songTitle;  // contains the Song title
	int releaseYear;   // contains the year the song was released
};

// Delare User-Functions
void ReadData(ifstream &myIn, SongsType arr[], int &numOfItems);
void DisplayMenu(int &choice);
void PrintByArtist(SongsType arr[],int numOfItems,string artistName);
void PrintByYear(SongsType arr[],int numOfItems,int targetYear);
void AddSong(SongsType arr[],int &numOfItems);
void DeleteSong(SongsType arr[],int &numOfItems);
int LinearSearch(SongsType arr[],int numOfItems,string targetSong);
void DisplayArray(SongsType arr[],int numOfItems);


const int MAX_ARRAY_SIZE = 500;

int main()
{
    SongsType arr[MAX_ARRAY_SIZE];  // ARRAY
    ifstream myIn;                  // input file stream
    int numOfItems=0;               // number of items in ARRAY
    int choice = -1;                // default choice
    string targetName;              // used to search/display an artistName in ARRAY
    int targetYear;                 // used to search/display songs in a chosen year

    // Read in DATA file into ARRAY
    ReadData(myIn,arr,numOfItems);
        
    while(choice != 5) {
        //always show MENU on iterations
        DisplayMenu(choice);
        
        // Validate input is a valid number
        if (choice<1 || choice>5) {
            cout << "Please choose a number between 1 and 5.\n\n";
            continue;
        
        // if User enter 1, prompt for artistName
        // Search for all listings associated with artistName
        } else if (choice == 1) {
            cout << "\nEnter the name of the Artist: ";
            getline(cin,targetName);
            cout << endl;
            PrintByArtist(arr,numOfItems,targetName);
        
        } else if (choice == 2) {
            cout << "\nEnter the Year to list hit songs: ";
            cin >> targetYear;
            cin.ignore(100,'\n');
            cout << endl;
            PrintByYear(arr,numOfItems,targetYear);
        
        } else if (choice == 3) {
            AddSong(arr,numOfItems);
        
        } else if (choice == 4) {
            DeleteSong(arr,numOfItems);
        }
        
    }
    
    return 0;
}


// Open DATA file, read DATA in to ARRAY objects, close file
void ReadData(ifstream &myIn, SongsType arr[], int &numOfItems) {

    myIn.open("topsongs.dat"); //open DATA file
    assert(myIn);  //confirm file opens
	
    // read the entire file for the order or $billboardRank, $artistName, $songTitle, $releaseYear
    while(myIn >> arr[numOfItems].billboardRank) {
        myIn.ignore(100,'\n'); // skip over newLineCHAR at end of cin before next read
        getline(myIn,arr[numOfItems].artistName);
        getline(myIn,arr[numOfItems].songTitle);
        myIn >> arr[numOfItems].releaseYear;
        myIn.ignore(100,'\n'); // skip over newLineCHAR at end of cin before next read
        numOfItems++;
    }
    myIn.close(); // close DATA file
}
// This function displays a menu of choices for User Input
// User chooses between 1-5 (validated in MAIN) 
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
    
    // Prompt/Get User $choice
    cout << setw(11) << ' ' << "Enter your choice: ";
    cin >> choice;
    cin.ignore(100,'\n');
    cout << setw(0); // restore "0" offset
}


// This function searches arr[] (FULL_ARRAY) for a $targetName
// if found, add to a temp ARRAY and display temp ARRAY results in table form
// if not found, print ERROR message
void PrintByArtist(SongsType arr[],int numOfItems,string targetName) {
    
    SongsType Matches[MAX_ARRAY_SIZE]; // new temporary ARRAY for MatchingInfo
    int counter = 0;  // numOfItems in temp ARRAY
    
    // go through FULL_ARRAY, if $artistName matches,
    // add to the MatchesARRAY, and add 1 to the 2nd ARRAY $counter
    for (int i=0; i<numOfItems ; i++) {
        if (targetName == arr[i].artistName) {
            Matches[counter] = arr[i];
            counter++;
        }
    }
    
    // if no hits were found by this $artistName, print ERROR message
    if (counter == 0) {
        cout << "ERROR: " << targetName << " had no hits songs in the past 4 years.\n";
    
    // otherwise, print title, billboardRank & releaseYear in table format
    } else {    
        
        //Display ARTIST HEADER
        cout << "Here are the songs by " << targetName << endl << endl;
        
        //Display COLUMN HEADERS
        cout << left << setw(30) << "Title" << setw(6) << "Rank" << setw(4) << "Year\n";
    
        // Print real info from Matches[]
        for (int i=0; i<counter; i++) {
            cout << setw(30) << Matches[i].songTitle
                 << setw(6)  << Matches[i].billboardRank
                 << setw(4)  << Matches[i].releaseYear << endl;
        }
    }
    cout << endl << endl; // blank line for readability
    setw(0); // set setw back to '0'
}



void PrintByYear(SongsType arr[],int numOfItems, int targetYear) {
    
    for (int i=0; i<numOfItems ; i++) {
        if (targetYear == arr[i].releaseYear){
            cout << arr[i].songTitle << endl;
        }
    }
    cout << endl << endl;
}

void AddSong(SongsType arr[],int &numOfItems) {
    SongsType newHit;
    
    cout << "Enter the new Song Title: ";
    getline(cin,newHit.songTitle);
    cout << "Enter the Artist Name: ";
    getline(cin,newHit.artistName);
    cout << "Enter the Song Rank: ";
    cin >> newHit.billboardRank;
    cin.ignore(100,'\n');
    cout << "Enter the Release Year: ";
    cin >> newHit.releaseYear;
    cin.ignore(100,'\n');
    
    arr[numOfItems] = newHit;
    numOfItems++;
}

void DeleteSong(SongsType arr[],int &numOfItems) {
    string targetSong;
    int loc;
    
    cout << "Enter the Song Title to be deleted: ";
    getline(cin,targetSong);
    
    loc = LinearSearch(arr,numOfItems,targetSong);
    cout << "numOfItems is " << numOfItems << endl;
    
    if (loc == -1) {
        cout << "ERROR: No matching Song Title was found.";
    } else {
        for (int i=loc; i<numOfItems; i++) {
            arr[i] = arr[i+1];
        }
        
    }
    numOfItems--;
    cout << "NEW numOfItems is " << numOfItems << endl;
}

int LinearSearch(SongsType arr[],int numOfItems,string targetSong) {
    for (int i = 0; i < numOfItems; i++) {
        if (arr[i].songTitle == targetSong)
            return i;
    }
    return -1;
}

//DEBUGGING FUNCTION
void DisplayArray(SongsType arr[],int numOfItems) {
    
    // display column HEADERS
    cout << left << setw(30) << "Title" << setw(6) << "Rank" << setw(4) << "Year\n";
    
    //cout << arr[numOfItems].billboardRank << ' ' << arr[numOfItems].artist << ' ' << arr[0].song << ' ' << arr[numOfItems].releaseYear << endl;
    
    for (int i=0; i<12; i++) {
        cout << setw(30) << arr[i].songTitle << setw(6) << arr[i].billboardRank << setw(4) << arr[i].releaseYear << endl;
    }
}
