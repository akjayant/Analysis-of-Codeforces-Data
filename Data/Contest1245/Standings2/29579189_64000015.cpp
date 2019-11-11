/// don't hack me

/// follow me: https://www.instagram.com/rose_culbece/

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define followmeoninsta ios_base::sync_with_stdio(0), cin.tie(0);
#define please if(1)

using namespace std;
string s;

ll mod = 1000000007;
ll dp[100002];
ll solve(ll x)
{
    dp[0] = 1;
    for(int i = 1; i <= x; ++i)
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    ll sol = dp[x];
    for(int i = 0; i <= x; ++i)
        dp[i] = 0;
    return sol;
}
int main()
{
    please followmeoninsta
    cin >> s;
    int nrcu = 0, nrcn = 0;
    ll ans = 1;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == 'm' || s[i] == 'w')
            ans = 0;
        if(s[i] != 'n')
            ans = (ans * solve(nrcn)) % mod, nrcn = 0;
        if(s[i] != 'u')
            ans = (ans * solve(nrcu)) % mod, nrcu = 0;
        if(s[i] == 'n')
            ++nrcn;
        if(s[i] == 'u')
            ++nrcu;
    }
    if(nrcn >= 2)
        ans = (ans * solve(nrcn)) % mod, nrcn = 0;
    if(nrcu >= 2)
        ans = (ans * solve(nrcu)) % mod, nrcu = 0;
    cout << ans;
    return 0;
}
