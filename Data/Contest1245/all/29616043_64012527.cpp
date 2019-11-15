/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 200005

ll dp[MAXN];

int main()
{
    _io
    string s; cin >> s;
    s = " " + s;
    if(s[1] == 'm' || s[1] == 'w')
        return cout << 0, 0;
    dp[0] = 1;
    dp[1] = 1;
    REP(i, 2, s.size())
    {
        dp[i] = dp[i-1];
        if(s[i] == s[i-1] && s[i] == 'u')
            dp[i] = (dp[i] + dp[i-2])%MOD;
        if(s[i] == s[i-1] && s[i] == 'n')
            dp[i] = (dp[i] + dp[i-2])%MOD;
        if(s[i] == 'm' || s[i] == 'w')
        return cout << 0, 0;
    }
    cout << dp[s.size()-1];
}
