/*input
4
5
4 3 1 4 5
4
4 4 4 4
3
1 1 1
5
5 5 1 1 5

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void solve(){
    int n;
    cin >> n;
    int a[n+1]{};
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] >= i){
            ans = max(ans,i);
        }
    }
    cout << ans;
    cout << endl;
}
signed main() {
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
return 0;
}
