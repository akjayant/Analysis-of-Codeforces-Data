/*
    Author: Nguyen Tan Bao
    Status:
    Idea:
*/
 
#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x
 
using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<int, II> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;
 
const ll MODBASE = 1000000007LL;
const int MAXN = 100010;
const int MAXM = 10010;
const int MAXK = 110;
const int MAXQ = 200010;

ll dp[MAXN];
string s;

ll add(ll a, ll b) {
    return (a + b) % MODBASE;
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> s;
    FOR(i,0,SZ(s)-1) 
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0;
            return 0;
        }
    int n = SZ(s);
    s = " " + s;
    dp[0] = 1;
    FOR(i,1,n) {
        dp[i] = add(dp[i], dp[i-1]);
        if (s[i] == 'u' && s[i-1] == 'u') dp[i] = add(dp[i], dp[i-2]);
        if (s[i] == 'n' && s[i-1] == 'n') dp[i] = add(dp[i], dp[i-2]);
    }
    cout << dp[n];
    return 0;
}
