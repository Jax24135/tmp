#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int randomNum;  // contains random number to determine which coin side
    int heads;      // contains the accumulated 'heads' count
    int count;      // contains the accumulated count of coin flips
    
    // Use Seed time of "0" to generated semi-random number
    srand(time(0));
    
    /* Use randomNum to determine "heads' or 'tails' based on an even/odd number.
     * Every time the coin lands on 'heads' incremen it until 3 consecutive 'heads'
     * If flip lands on 'tails', reset 'heads' counter.
     * 
     * Keep a running total counter either way to show total flips in output.
     */ 
    while (heads < 3) {
            randomNum = rand();
            
            // if 'heads' is flipped - add 1 to 'heads' counter (until it reaches 3)
            // add +1 to counter && print "Heads"
            if (randomNum%2 == 0){
                ++heads;
                ++count;
                cout << "Head\n";
            
            // if 'tail is flipped, reset 'heads' counter, add +1 to counter
            // and print "Tails"
            } else {
                ++count;
                heads = 0;
                cout << "Tail\n";
            }
    }
    
    // Print total results of coin flips to User Screen
    cout << "It took " << count << " flips to get 3 consecutive heads.\n";
       
    // Exit program cleanly
    return 0;
}
