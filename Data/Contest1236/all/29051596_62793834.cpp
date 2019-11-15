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

vi v[310];
int main() {
    ios::sync_with_stdio(0);
    int n; cin >>n;
    int idx = 0, turn = 0;
    forn(i, 1, n) {
        if (turn) forn(j, 1, n) v[j].pb(++idx);
            else ford(j, n, 1) v[j].pb(++idx);
        turn ^= 1;
    }
    forn(i, 1, n) { for(auto x: v[i]) cout << x << ' '; cout << '\n'; }
    return 0;
}