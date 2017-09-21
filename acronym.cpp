#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    string line = "national aeronautics space assessement";
    int loc = 0;
    string acronym;
        
    acronym = toupper(line[loc]);
    
    while (loc != string::npos) {
        loc = line.find(' ',loc+1);
        
        if (loc != string::npos){
         acronym += toupper(line[loc+1]);   
        }
        
        cout << "loc is " << loc << endl;
    }
    
    cout << acronym;    
    
    return 0;
}

