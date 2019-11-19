#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+7;
const int mod=1e9+7;
ll a[maxn];
ll sum[maxn];
int n,m;
int main(){
   cin>>n>>m;
    a[2]=2,a[3]=2;
    sum[2]=2,sum[3]=a[2]+a[3];
    
    for(int i=4;i<=max(n,m)+1;++i){
        a[i]=(a[i-1]+a[i-2])%mod,sum[i]=(sum[i-1]+a[i])%mod;
    } 
    ll ans=(2+sum[n]+sum[m])%mod;
    cout<<ans<<endl;
    return 0;
}
