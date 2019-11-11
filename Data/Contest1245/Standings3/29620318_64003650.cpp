#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;


int main() {
    int t;cin >> t;
    REP(j,t) {
        int n;
        cin >> n;
        int p,c,g;cin >> g >> p >> c;
        string s;cin >> s;
        vector<char> ans(n,'N');
        REP(i,n) {
            if (s[i] == 'R') {
                if (p > 0) {
                    p--;
                    ans[i] = 'P';
                }
            }
            else if (s[i] == 'P') {
                if (c > 0) {
                    c--;
                    ans[i] = 'S';
                }
            }
            else if (s[i] == 'S') {
                if (g > 0) {
                    g--;
                    ans[i] = 'R';
                }
            }
        }
        int cnt = n;
        REP(i,n) {
            if (ans[i] == 'N') {
                cnt--;
                if (g > 0) {
                    g--;
                    ans[i] = 'R';
                }
                else if (p > 0) {
                    p--;
                    ans[i] = 'P';
                }
                else if (c > 0) {
                    c--;
                    ans[i] = 'S';
                }
            }
        }
        if (cnt >= (n + 1)/2) {
            puts("YES");
            REP(i,n) {
                cout << ans[i];
            }
            cout << endl;
        }
        else {
            puts("NO");
        }
    }
    return 0;
}