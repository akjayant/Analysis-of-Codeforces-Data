#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
typedef long long ll;
int i;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        int res = 0;
        for(int i = 0; i <= a && 2*i <= b; ++i) {
            int newB = b-i-i;
            int curr = 3*i;
            curr +=3*min(newB, c/2);
            res = max(res, curr);
        }
        cout << res << endl;
    }
}
