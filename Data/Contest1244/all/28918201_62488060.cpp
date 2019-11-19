#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define int long long
#define double long double
#define _ << ' ' <<
#define For(i,z) for(int32_t i=0;i<(z);i++)
#define sqr(a) ((a)*(a))

#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

template<typename T, typename K> inline void umax(T &a, K b) { a = max(a, (T)b); }
template<typename T, typename K> inline void umin(T &a, K b) { a = min(a, (T)b); }

const int32_t N = 1e5+10;
const int INF = 1e16 + 10;
const pii NINF = make_pair(INF, INF);
const double EPS = 1e-6;
const int II = 1e9;
const int MOD = 1e9 + 7;

vector <int> gr[N];
int cost[N][3];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    For (i, 3)
        For (j, n)
            cin >> cost[j][i];

    For (i, n-1) {
        int a, b; cin >> a >> b; a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    For (i, n)
        if (gr[i].size() > 2) {
            cout << "-1\n"; return 0;
        }

    vector <int> pat(3);
    For (i, 3) pat[i] = i;
    int st = 0;
    For (i, n)
        if (gr[i].size() == 1) {
            st = i; break;
        }

    int ans = INF;
    vector <int> anspat(n);
    do {
        vector <int> curpat(n);
        int cur = 0, v = st, idx = 0, p = -1;
        while (true) {
            cur += cost[v][pat[idx]];
            curpat[v] = pat[idx];
            idx = (idx + 1) % 3;

            if (v != st && gr[v].size() == 1)
                break;

            if (p == gr[v][0]) {
                p = v;
                v = gr[v][1];
            } else {
                p = v;
                v = gr[v][0];
            }
        }
        if (ans > cur) {
            ans = cur;
            For (i, n)
                anspat[i] = curpat[i];
        }
    } while(next_permutation(pat.begin(), pat.end()));

    cout << ans << '\n';
    For (i, n)
        cout << anspat[i] + 1 << ' ';
}
