#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long LL;
#define foru(i,a,b) for(LL i=a;i<=b;i++)
#define ford(i,a,b) for(LL i=a;i>=b;i--)
const LL N=1e5+10;
const LL sac=1e9+7;
LL n,m;

LL po(LL a,LL b){
	LL ret=1,base=a;
	while(b){
		if(b%2){ret*=base;ret%=sac;}
		b>>=1;
		base*=base;
		base%=sac;
	}
	return ret;
}

int main(){
	scanf("%I64d%I64d",&n,&m);
	LL ans=po(po(2,m)-1,n);
	printf("%I64d\n",ans);
}