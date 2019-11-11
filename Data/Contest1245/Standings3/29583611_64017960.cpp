#include <bits/stdc++.h>
#define MAXN 100007LL
#define MOD 1000000007LL

using namespace std;

int n;
long long dp[MAXN];
string s;


int solve( int idx ){
    if(idx == n)
        return 1;
    long long& ref = dp[idx];
    if( ref != -1 )
        return ref;
    ref = 0;
    if( s[idx] != 'm' && s[idx] != 'w' ) 
        ref = solve(idx + 1);
    if(idx < n - 1 && s[idx] == 'u' && s[idx + 1] == 'u')
        ref += solve(idx + 2);
    if(idx < n - 1 && s[idx] == 'n' && s[idx + 1] == 'n')
        ref += solve(idx + 2);
    ref %= MOD;
    return ref;
}

int main()
{
    memset( dp, -1, sizeof dp );
    cin >> s;
    n = s.length();
    cout << solve(0) << endl;

    return 0;
}