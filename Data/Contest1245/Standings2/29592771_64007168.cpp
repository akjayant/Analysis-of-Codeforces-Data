#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1000000007, nMax = 100000;

ll n, i, ans = 1, j, st;

ll dp[nMax + 10];

string s;

int main()
{
    dp[0] = dp[1] = 1;
    for(i=2; i<=nMax; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;

    cin >> s;
    n = s.length();

    for(auto it : s)
        if(it == 'm' || it == 'w')
        {
            cout << 0;
            return 0;
        }

    for(i=0; i<n; i++)
    {
        if(s[i] == 'u')
        {
            st = 0;
            j = i;
            while(j < n && s[j] == 'u') j++;
            j--;
            ans = (ans * dp[j-i+1]) % MOD;
            i = j;
        }
        else if(s[i] == 'n')
        {
            st = 0;
            j = i;
            while(j < n && s[j] == 'n') j++;
            j--;
            ans = (ans * dp[j-i+1]) % MOD;
            i = j;
        }
    }
    cout << ans;
    return 0;
}
