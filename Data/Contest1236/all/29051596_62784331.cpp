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

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for(; t; t--) {
    int a, b, c; 
    cin >> a >> b >> c;
    int ans = 0;
    ans += min(c/2, b) * 3;
    b -= min(c/2, b);
    ans += min(b/2, a) * 3;
    cout << ans <<'\n';
    }
    return 0;
}