#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
typedef long long ll;
int n,m;
const ll P=1e9+7;
ll ans;
ll f[100500];
int main(){
    scanf("%d%d",&n,&m);
    f[1]=f[2]=2;
    rep(i,3,100000) f[i]=(f[i-1]+f[i-2])%P;  
    //rep(i,1,10) printf("%lld\n",f[i]/2);
    ans=2;
    rep(i,1,n-1) ans=(ans+f[i])%P;
    rep(i,1,m-1) ans=(ans+f[i])%P;
    printf("%lld\n",ans);
    return 0;
}