#include <iostream>
using namespace std;


int syracuse(int n, int countdown, int &highest) 
{
    if (n > highest)
        highest = n;
    
    //base case
    if (n == 1)
        return 1;
        
    //base case    
    if (countdown == 0)
        return 0;     
        
    if (n % 2 == 0)
    {//even condition
        int nUpdated = n / 2;
        cout << n << "\t\t\t" << nUpdated << endl;
        
        return syracuse(nUpdated, --countdown, highest);
    } 
    else
    {//odd condition
        int nUpdated = (3*n + 1) / 2;
        cout << n << "\t\t\t" << nUpdated << endl;
        
        return syracuse(nUpdated, --countdown, highest);
    }
}


int main()
{
    int start;
    int lim;
    bool startInvalid = true;
    bool limitInvalid = true;
    
    int highest{0};
    
    while (startInvalid)
    {
        cout << "Enter a starting number: ";
        cin >> start;
        
        if (start >= 1)
            startInvalid = false;
    }
    
    while (limitInvalid)
    {
        cout << "Enter a limit of terms: ";
        cin >> lim;
        
        if (lim >= 1)
            limitInvalid = false;
    }
    
    
    cout << "Number: " << start << endl;
    cout << "Term limit: " << lim << endl;
    cout << "Input Number\t\tsyracuse(n)\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    if( !(syracuse(start, lim, highest)) )
        cout << "Sequence was aborted early\n";
        
    cout << "\nHighest number reached: " << highest;

    return 0;
}