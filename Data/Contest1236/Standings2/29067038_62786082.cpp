#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod=1e9+7;
LL pow2(LL x,LL p){
    LL ans=1ll;
    for(;p;p>>=1ll,x=x*x%mod)if(p&1ll)ans=ans*x%mod;
    return ans;
}
int main(){
    LL n,m;
    cin>>n>>m;
    cout<<pow2(pow2(2ll,m)-1,n);
}
