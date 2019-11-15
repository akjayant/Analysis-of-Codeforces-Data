#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int x, y, z;
        cin>>x>>y>>z;
        int alpha = z/2;
        alpha = min(alpha, y);
        int ans = 3*alpha;
        y-=alpha;
        y/=2;
        alpha = min(y, x);
        ans += 3*alpha;
        cout<<ans<<endl;
    }
    return 0;
}