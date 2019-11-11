#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000007;

int cache[100005];

int fib(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(cache[n] == 0){
        cache[n] = (fib(n-1) + fib(n-2)) % MOD;
    }
    return cache[n];
}

void solve()
{
    string s; cin >> s;
    int n = s.length();

    if(s.find('w') != s.npos || s.find('m') != s.npos){
        cout << 0;
        return;
    }

    int i =0;
    int ans = 1;
    while(i < n){
        if(s[i] == 'n' || s[i] == 'u'){
            char c = s[i];
            int len = 1;
            while(i+len < n && s[i+len] == c)
                len++;
            // cout << ">" << len <<'\n';
            ans *= fib(len+1);
            ans %= MOD;
            i = i+len;
        }
        else
            i++;
    }

    cout << ans;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int T;
    // cin >> T;

    // for(int i = 0; i < T; i++)
        solve();
}