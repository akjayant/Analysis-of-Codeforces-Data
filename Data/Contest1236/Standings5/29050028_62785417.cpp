/*input
3
3 4 5
1 0 5
5 3 2
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
    IOS;
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int ans = 0;
        int t = min(b,c/2);
        c -=  2 * t;
        b -= t;
        ans += 3 * t;
        t = min(a, b/2);
        ans += 3 * t;
        cout << ans << endl;
    }
return 0;
}
