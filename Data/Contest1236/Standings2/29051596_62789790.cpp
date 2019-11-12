#include <bits/stdc++.h>
using namespace std;
#define llong       long long
#define vi          vector<llong>
#define pr          pair<llong, llong>
#define pb          push_back
#define ft          first
#define nd          second

#define forn(i, a, b)                   for(int i=a; i<=b; ++i)
#define ford(i, a, b)                   for(int i=a; i>=b; --i)
#define repn(i, a, b)                   for(int i=a; i <b; ++i)
#define repd(i, a, b)                   for(int i=(int)a-1; i>=b; --i)

template<class T, class U> T max(const T &a, const U &b) { if (a > b) return a; return b; }
template<class T, class U> T min(const T &a, const U &b) { if (a < b) return a; return b; }
template<class T, class U> void maximize(T &a, const U &b) { a = max(a, b); }
template<class T, class U> void minimize(T &a, const U &b) { a = min(a, b); }
const int MOD = 1e9 + 7;
llong pw(llong a, llong q) {
    if (q == 0) return 1;
    llong tmp = pw(a, q/2);
    tmp = tmp * tmp % MOD;
    if (q & 1) tmp = tmp * a % MOD;
    return tmp;
}
int main() {
    ios::sync_with_stdio(0);
    llong n, m; 
    cin >> n >> m;
    cout << pw( (pw(2, m) - 1 + MOD) % MOD, n );
    return 0;
}