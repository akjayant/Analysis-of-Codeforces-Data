#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

signed main()
{
    int nbQueries;
    cin >> nbQueries;
    
    for (int idQuery = 0; idQuery < nbQueries; ++ idQuery)
    {
        int entier1, entier2;
        cin >> entier1 >> entier2;
        
        if (__gcd(entier1, entier2) != 1)
            cout << "Infinite\n";
        else
            cout << "Finite\n";
    }
    return 0;
}