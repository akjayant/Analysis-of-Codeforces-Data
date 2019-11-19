#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod=1e9+7;
#define LL long long
const int maxn=1e5+5;
LL pow2(LL x,LL p){
    LL ans=1;
    for(;p;p>>=1ll,x=x*x%mod)if(p&1ll)ans=ans*x%mod;
    return ans;
}
LL f[maxn];
int ansm=0;
int main(){
    scanf("%d%d",&n,&m);
    if(m>n)swap(n,m);
    LL ans=pow2(2,n);
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
		
	}
    printf("%d\n",((((f[n]+f[m]-1)%mod+mod)%mod)*2)%mod);
}
