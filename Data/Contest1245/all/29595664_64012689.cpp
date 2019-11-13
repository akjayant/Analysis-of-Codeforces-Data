#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define DB( x ) cout << #x << " = " << x << endl;
#define sz(s) ((int)((s).size()))
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> tri;
typedef vector <vector <ll>> matrix;
typedef pair<string, string> pss;

const ll mod = (ll)1e9 + 7;
const int MAX = 100001;

const int oo = 0x3f3f3f3f;

string s; int n;

ll dp[MAX];

ll Solve(int index){

    if(index == n)
        return 1;

    if(dp[index] != -1)
        return dp[index];

    ll ans = 0;

    if(s[index] == 'n'){
        if(index + 1 < n)
            if(s[index + 1] == 'n')
                ans = (ans + Solve(index + 2)) % mod;
        ans = (ans + Solve(index + 1)) % mod;

    }
    else if(s[index] == 'u'){
        if(index + 1 < n)
            if(s[index + 1] == 'u')
                ans = (ans + Solve(index + 2)) % mod;
        ans = (ans + Solve(index + 1)) % mod;
    }
    else ans = (ans + Solve(index + 1)) % mod;

    return dp[index] = ans;
}


int main() {

    ios_base :: sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;

    while(tc--){
        int a,b; cin >> a>> b;

        if(__gcd(a, b) > 1)
            cout << "Infinite\n";
        else cout << "Finite\n";
    }
}