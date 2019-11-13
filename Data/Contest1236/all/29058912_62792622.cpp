#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> res(n,vector<int>(n));
    int pos = 1;
    for(int j = 0; j < n; ++j) {
        for(int i = 0; i < n; ++i) {
            res[i][j] = pos++;
        }
    }
    for(int i = 0; i*2 < n; ++i) {
        for(int j = 1; j < n; j+=2) {
            swap(res[i][j], res[n-i-1][j]);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}
