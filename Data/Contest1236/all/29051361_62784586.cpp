#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define REP(i, r) for(int i = (int)0; i < (int)r; ++i)
#define FORD(i, l, r) for(int i = (int)l; i >= (int)r; --i)
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int T, a, b, c;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef yt
        freopen("in.inp", "r", stdin);
    #endif
    cin >> T;
    while(T--) {
        cin >> a >> b >> c;
        int ans = 0;
        FOR(i, 0, a) {
            if (i * 2 > b) break;
            int tmp = 3 * i, le = b - 2 * i;
            tmp += min(le, c / 2) * 3;
            ans = max(ans, tmp);
        }
        cout << ans << '\n';
    }
}

