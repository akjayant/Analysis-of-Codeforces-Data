#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define REP(i, r) for(int i = (int)0; i < (int)r; ++i)
#define FORD(i, l, r) for(int i = (int)l; i >= (int)r; --i)
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int Nmax = 112;

int t, n, r, p, c;
string s;
char res[Nmax];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef yt
        freopen("in.inp", "r", stdin);
    #endif // yt
    cin >> t;
    while(t--) {
        cin >> n >> r >> p >> c >> s;
        int cnt = 0;
        REP(i, n) {
            if (s[i] == 'R' && p) {
                --p;
                res[i] = 'P';
                ++cnt;
            } else if (s[i] == 'P' && c) {
                --c;
                res[i] = 'S';
                ++cnt;
            } else if (s[i] == 'S' && r) {
                --r;
                res[i] = 'R';
                ++cnt;
            } else res[i] = 0;
        }
        REP(i, n) {
            if (res[i] == 0) {
                if (r) {
                    --r; res[i] = 'R';
                } else if (p) {
                    --p; res[i] = 'P';
                } else {
                    --c;
                    res[i] = 'S';
                }
            }
        }
        if (cnt >= (n + 1) / 2) {
            cout << "YES\n";
            REP(i, n) cout << res[i];
            cout << '\n';
        } else cout << "NO\n";
    }
}
