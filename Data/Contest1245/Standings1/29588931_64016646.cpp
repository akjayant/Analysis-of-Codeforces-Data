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
llong dp[50][3][3][3][3];
string ll, rr;
int n;
llong backtrack(int i, int gra, int sma, int grb, int smb) {
    llong &ans = dp[i][gra][sma][grb][smb];
    if (ans != -1) return ans;
    if (i == n) { return ans = 1; };
    ans = 0;
    forn(j, (gra ? 0 : ll[i] - '0'), (sma ? 1 : rr[i] - '0')) {
        forn(k, (grb ? 0 : ll[i] - '0'), (smb ? 1 : rr[i] - '0')) {
            if (j == 1 && k == 1) continue;
            ans += backtrack(i+1, gra || j > (ll[i]-'0'), sma || j < (rr[i]-'0'), grb || k > (ll[i]-'0'), smb || k < (rr[i]-'0'));
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for(; t; t--) {
        llong l, r; cin >> l >> r;
        ll = rr = "";
        while (l) {
            ll += char( l%2 + '0' );
            l /= 2;
        }
        while (r) {
            rr += char( r%2 + '0' );
            r /= 2;
        }
        while (ll.size() < rr.size()) ll += '0';
        reverse(ll.begin(), ll.end());
        reverse(rr.begin(), rr.end());
        n = rr.size();
        memset(dp, -1, sizeof dp);
        cout << backtrack(0, 0, 0, 0, 0) << '\n';
    }
    return 0;
}