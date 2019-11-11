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

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for(; t; t--) {
        int n; cin >> n;
        int a, b, c; cin >> a >> b >> c;
        string s; cin >> s;
        int aa, bb, cc;
        aa = bb = cc = 0;
        for(auto x: s) {
            if (x == 'R') aa ++;
            if (x == 'P') bb ++;
            if (x == 'S') cc ++;
        }
        int sum = min(aa, b) + min(bb, c) + min(cc, a);
        if (sum >= (n+1) / 2) { cout << "YES\n";
        string str = "";
        repn(i, 0, s.size()) str += 'x'; 
        repn(i, 0, s.size()) {
                if (s[i] == 'R') if (b) { str[i] = 'P'; b --; continue; }
                if (s[i] == 'P') if (c) { str[i] = 'S'; c --; continue; }
                if (s[i] == 'S') if (a) { str[i] = 'R'; a --; continue; }
            }
        repn(i, 0, s.size()) if (str[i] == 'x') {
            if (a) { a--; str[i] = 'R'; continue; }
            if (b) { b--; str[i] = 'P'; continue; }
            if (c) { c--; str[i] = 'S'; continue; }
        }
        cout << str << '\n';
        continue;
        }
        cout << "NO\n";
    }
    return 0;
}