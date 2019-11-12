#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
using namespace std;
const ll MOD = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int> > ans(n);
    int mode = 1;
    int cur = 0;
    for(int i = n * n ; i > 0 ; i--) {
        ans[cur].pb(i);
        cur += mode;
        if(cur == n || cur == -1) {
            mode *= -1;
            cur += mode;
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for(auto t : ans[i]) {
            cout << t << " ";
        }
        cout << '\n';
    }
    return 0;
}