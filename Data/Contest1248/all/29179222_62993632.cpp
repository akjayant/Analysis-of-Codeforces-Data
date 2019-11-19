#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
int f[maxn],n,m;
void solve(){
    scanf("%d%d",&n,&m);
    f[1]=1;
    f[2]=1;
    for(int i=3,ie=max(n,m);i<=ie;++i){
        f[i]=(f[i-2]+f[i-1])%mod;
    }
    for(int i=1,ie=max(n,m);i<=ie;++i){
        f[i]=(f[i]+f[i-1])%mod;
    }
    cout<<(2ll+2ll*f[n-1]+2ll*f[m-1])%mod<<endl;
}
int main(){
    solve();

    return 0;
}