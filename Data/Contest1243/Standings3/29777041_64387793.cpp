#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[100005];
int main()
{
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        ll n;cin >> n;
        int cnt=0;
        for (ll i=2;i*i<=n;i++){
            if(n%i==0){
                c[cnt++]=i;
                if(i*i!=n) c[cnt++]=n/i;
            }
        }
        c[cnt++]=n;
        ll ans=0;
        for (int i=0;i<cnt;i++){
            ans=__gcd(ans,c[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
