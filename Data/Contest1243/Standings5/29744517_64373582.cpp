#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 112;
const int M = 19;
const int MOD = 1e9 + 7;

signed main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), greater <int> ());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int k = min(i + 1, v[i]);
            ans = max(k, ans);
        } 
        cout << ans << '\n';
    }    

}