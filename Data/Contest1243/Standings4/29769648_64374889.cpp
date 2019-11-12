#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
#define endl "\n"
const ll mod = 1000000007;
 
void testCase() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> v;
        for (int i=0; i<n; i++) {
            int val;
            cin >> val;
            v.push_back (val);
        }
        sort (v.begin(), v.end());
        reverse (v.begin(), v.end());
        int ans = 0;
        for (int i=1; i<=n; i++) {
            int mn = 1e9;
            for (int j=0; j<i; j++) {
                mn = min (mn, v[j]);
            }
            if (mn >= i) {
                ans = i;
            }
        }
        cout << ans << endl;
    }
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}