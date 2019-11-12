#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e9;
// const LL oo = 1e16 + 5;
const int MOD = 1e9 + 7;
const int N = 2e5+5;
// const int MOD = 998244353;
// const long double PI = acos(-1);

vector<int> ans[N];
void solve() {
    int n, i, j, k = 1;
    cin >> n;
    for (i=0;i<n;i++) {
        if (i & 1) {
            for (j=n-1;j>=0;j--) {
                ans[j].push_back(k);
                k++;
            }
        } else {
            for (j=0;j<n;j++) {
                ans[j].push_back(k);
                k++;
            }
        }
    }
    for (i=0;i<n;i++) for (j=0;j<n;j++) cout << ans[i][j] << " \n"[j==n-1];
}

int main() {
    FASTIO; int t = 1; 
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}