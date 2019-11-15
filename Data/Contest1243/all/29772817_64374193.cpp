#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define int long long
#define mod 100000007

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int n; cin >> n;
        while ( n-- ) {
                int t; cin >> t;
                vector<int> v;
                lp(i, t) { int a; cin >> a; v.push_back(a); }
                sort(all(v));
                int ans = 0;
                for (int i = 0; i < t; i++) {
                        int w = t - i;
                        int h = v[i];
                        ans = max(ans, min(h, w));
                }
                cout << ans<< "\n";
        }
return 0;
}
