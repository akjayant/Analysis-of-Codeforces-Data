#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

int main() {
    int t; cin >> t;
    REP(k, t) {
        int n, m; cin >> n;
        ll n_0 = 0, n_1 = 0;
        REP(i, n) {
            int a; cin >> a;
            if (a & 1) n_1++;
            else n_0++;
        }
        cin >> m;
        ll m_0 = 0, m_1 = 0;
        REP(i, m) {
            int a; cin >> a;
            if (a & 1) m_1++;
            else m_0++;
        }
        cout << n_0 * m_0 + n_1 * m_1 << endl;
    }
    return 0;
}