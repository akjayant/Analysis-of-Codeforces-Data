#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int dp[(int)1e5 + 1][2];

signed main()
{
    string chaine;
    getline(cin, chaine);
    
    dp[0][0] =  1;
    dp[0][1] = 0;
    
    for (int iCara = 1; iCara < (int) chaine.length(); ++iCara)
    {
        if (chaine[iCara] == chaine[iCara - 1] && (chaine[iCara] == 'n' || chaine[iCara] == 'u'))
            dp[iCara][1] = dp[iCara - 1][0];
        else
            dp[iCara][1] = 0;
        dp[iCara][0] = dp[iCara - 1][1] + dp[iCara - 1][0] ;
        
        
        dp[iCara][0] %= MOD;
        dp[iCara][1] %= MOD;
        //cout << dp[iCara][1]<<" " << dp[iCara][0] << endl;
    }
    
    bool problem = false;
    for (int i = 0; i < (int)chaine.length(); ++i)
        problem |= (chaine[i] == 'w' || chaine[i] == 'm');
    if (problem)
        cout << 0;
    else
        cout << (dp[(int)chaine.length() - 1][0] + dp[(int)chaine.length() - 1][1])%MOD;
    return 0;
} 