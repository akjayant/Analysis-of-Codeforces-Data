#include <bits/stdc++.h>
using namespace std;
#define llong       long long
#define vi          vector<llong>
#define pr          pair<llong, llong>
#define pb          push_back
#define st          first
#define nd          second

#define forn(i, a, b)                   for(int i=a; i<=b; ++i)
#define ford(i, a, b)                   for(int i=a; i>=b; --i)
#define repn(i, a, b)                   for(int i=a; i <b; ++i)
#define repd(i, a, b)                   for(int i=(int)a-1; i>=b; --i)

template<class T, class U> T max(const T &a, const U &b) { if (a > b) return a; return b; }
template<class T, class U> T min(const T &a, const U &b) { if (a < b) return a; return b; }
template<class T, class U> void maximize(T &a, const U &b) { a = max(a, b); }
template<class T, class U> void minimize(T &a, const U &b) { a = min(a, b); }
const llong MOD = 1e9 + 7;
const llong N = 1e5 + 10;
llong f[N];
int main() {
    ios::sync_with_stdio(0);
    f[0] = f[1] = 1;
    string s;
    cin >> s;
    s = ' ' + s;
    for(auto x: s) if ( x == 'w' || x == 'm') { cout << 0; return 0; }
    int n = s.size();
    forn(i, 2, n) f[i] = (f[i-1] + f[i-2]) % MOD;
    llong ans = 1;
    forn(i, 1, n) if (s[i] == 'u' || s[i] == 'n') {
        llong cur = 1;
        while (i < n && s[i+1] == s[i]) { i++; cur ++; }
        ans = ans * f[cur] % MOD;
    }
    cout << ans << '\n';
    return 0;
}