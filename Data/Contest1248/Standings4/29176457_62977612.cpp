#include <bits/stdc++.h>
#define stop system("pause")
#define INP freopen("input.txt","r",stdin)
#define OUTP freopen("output.txt","w",stdout)
#define int long long
using namespace std;

typedef long long ll;

void solve(){
    int odd1,even1;
    odd1 = even1 = 0;
    int n; cin >> n;
    for(int i(0); i < n;i++){
        int x; cin >> x;
        if(x%2 == 0)even1++;
        else odd1++;
    }
    int m; cin >> m;
    int ans = 0;
    for(int i(0); i < m;i++){
        int x; cin >> x;
        if(x%2 == 0)ans+=even1;
        else ans+=odd1;
    }
    cout << ans << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int t;  cin >> t;
    for(int i(0); i < t;i++){
        solve();
    }
    return 0;
}
/*
*/
