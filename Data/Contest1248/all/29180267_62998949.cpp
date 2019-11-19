#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define mp make_pair
#define ii pair<long long, long long>
#define MOD 1000000007LL

ll dp[100005];

ll solve(int rem)
{
    if(rem == 1)
        return 1LL;
    else if(rem == 2)
        return 2LL;
    else
    {
        if(dp[rem] != -1)
            return dp[rem];
        else
        {
            dp[rem] = (solve(rem - 1) + solve(rem - 2) + MOD) % MOD;
        }
        return dp[rem];
    }
}

int n, m;
ll res = 0;
int main()
{
    while(cin >> n >> m)
    {


            dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= max(n, m); i++)
        {
            dp[i] = (dp[(i - 1)] + dp[(i - 2)] + MOD) % MOD;
        }
        cout << (2 * (dp[n] + dp[m] - 1) + MOD) % MOD << endl;


    }

    return 0;
}
