#include<bits/stdc++.h>
#define see(x) cout<<#x<<" = "<<x<<endl

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll PowerMod(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while(b>0) {
        if(b % 2 == 1)
        ans = (ans * a) % c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}
int main(){
ll n,m,ans;
cin>>n>>m;
ans=PowerMod(2,m,mod)-1;
ans=PowerMod(ans,n,mod);
printf("%lld\n",(ans%mod+mod)%mod);
return 0;
}
