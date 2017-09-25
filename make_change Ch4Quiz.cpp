#include <iostream>
using namespace std;

void VerifyChange (int &cointValue);
void computeCoin(int &cointValue,int &number, int &amountLeft, int &quarters, int &dimes, int &pennies);
void PrintResults(int &quarters,int &dimes, int &pennies);

int main()
{
    //int cointValue = 0, number=0, amountLeft=0, quarters=0, dimes=0, pennies=0;
    char runAgain = 'Y';
	
    while (runAgain == 'Y') {
        int cointValue = 0, number=0, amountLeft=0, quarters=0, dimes=0, pennies=0;
	VerifyChange(cointValue);
	computeCoin(cointValue, number, amountLeft, quarters, dimes, pennies);
	PrintResults(quarters, dimes, pennies);
        
        cout << "Do you want to make change again?\n"
             << "Enter Y to convert again and any other key to exit:";
        cin >> runAgain;
    }
        
}


void VerifyChange (int &cointValue) {
	cout << "Enter the amount of change:";
	cin >> cointValue;
	
	while (cointValue < 1 || cointValue > 99) {
		cout << "Enter a value between 1 and 99:";
		cin >> cointValue;
        }
}

void computeCoin(int &cointValue, int &number, int &amountLeft, int &quarters, int &dimes, int &pennies) {
    amountLeft = cointValue;
    
    if (amountLeft > 24) {
        quarters = (amountLeft / 25);
        amountLeft = (amountLeft % 25);
    }
    if (amountLeft > 9) {
        dimes = (amountLeft / 10);
        amountLeft = (amountLeft % 10);
    }
    
    pennies = amountLeft;
}

void PrintResults(int &quarters,int &dimes, int &pennies) {
    cout << "Change can be given as:\n"
         << quarters << " quarter(s)\n"
         << dimes << " dime(s)\n"
         << pennies << " penny (pennies)\n";    
}
