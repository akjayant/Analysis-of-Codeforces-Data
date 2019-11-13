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
const int Nmax = 311;

int n;
vector<int> a[Nmax];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef yt
        freopen("in.inp", "r", stdin);
    #endif
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n * n; i += n) {
        ++cnt;
        FOR(j, i, i + n - 1) {
            a[cnt].push_back(j);
        }
        if (cnt % 2 == 1) reverse(a[cnt].begin(), a[cnt].end());
    }
    FOR(i, 1, n) {
        FOR(j, 1, n) cout << a[j][i - 1] << ' ';
        cout << '\n';
    }
}
