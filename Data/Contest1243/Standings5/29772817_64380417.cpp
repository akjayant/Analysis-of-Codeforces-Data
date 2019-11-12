#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define int long long
#define mod 100000007

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int t; cin >> t;
        while ( t-- ) {
                int n; cin >> n;
                string a, b; cin >> a>> b;
                string aa = "", bb = "";
                lp(i, n) {
                        if (a[i] != b[i]) {
                                aa += a[i];
                                bb += b[i];
                        }
                }
                if (aa.size() == 2 && aa[0] == aa[1] && bb[0] == bb[1]) cout << "Yes\n";
                else cout << "No\n";
        }
return 0;
}
