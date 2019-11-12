#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int a[3];
        for(int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        int ans = 0;
        while(true) {
            int done = 0;
            if(a[1] >= 1 && a[2] >= 2) {
                a[1] -= 1;
                a[2] -= 2;
                ans += 3;
                done++;
            }
            else if(a[0] >= 1 && a[1] >= 2) {
                a[0] -= 1;
                a[1] -= 2;
                ans += 3;
                done++;
            }
            if(!done) break;
        }
        cout << ans << endl;
    }
	
	return 0;
}
