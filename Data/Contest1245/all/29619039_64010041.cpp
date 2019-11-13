#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back


#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long
#define eps 1e-8

const int N = 1e6 + 5;
const int VAL = log2(VAL) + 2;
char f[N];
int dp[N] , mod = 1e9 + 7;

int add(int a , int b)
{
    return (a + b) % mod;
}

main()
{
    //freopen("task.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> f;
    int n = strlen(f);
    FORD(i , n , 1)
    {
        f[i] = f[i - 1];
        if(f[i] == 'm' || f[i] == 'w')
        {
            cout << "0";
            exit(0);
        }
    }
    dp[0] = 1;
    FOR(i , 1 , n)
    {
        dp[i] = dp[i - 1];
        if(f[i] == 'n' && f[i - 1] == 'n')
            dp[i] = add(dp[i] , dp[i - 2]);
        if(f[i] == 'u' && f[i - 1] == 'u')
            dp[i] = add(dp[i] , dp[i - 2]);
    }
    cout << dp[n];
}
