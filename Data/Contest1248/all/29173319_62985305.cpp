#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll tate = 0, yoko = 0;
    int t = n / 2;
    REP(i, t) {
        tate += a[i];
    }
    FOR(i, t, n) {
        yoko += a[i];
    }
    cout << tate * tate + yoko * yoko << endl;
    return 0;
}