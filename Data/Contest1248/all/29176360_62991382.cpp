#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define xmod 1000000007
using namespace std;

ll n,m,ans,on,tw,fac[100005],num;
ll fpow(ll a,ll b){
	ll ans=1,base=a;
	while (b > 0){
		if ((b&1) == 1) ans=ans*base%xmod;
		base=base*base%xmod;
		b/=2;
	}
	return ans;
}
int main(){
	scanf("%lld%lld",&n,&m);
	fac[0]=1;
	for (int i=1;i<=100000;i++){
		fac[i]=fac[i-1]*i;
		fac[i]%=xmod;
	}
	ans=2;
	for (int i=1;i<=n/2;i++){
		on=n-i*2;
		tw=i;
		num=(((fac[on+tw]%xmod)*(fpow(fac[on],xmod-2)%xmod)%xmod)*(fpow(fac[tw],xmod-2)%xmod))%xmod;
		ans+=num*2;
		ans%=xmod;
		//printf("%lld\n",num);
	}
	for (int i=1;i<=m/2;i++){
		on=m-i*2;
		tw=i;
		num=(((fac[on+tw]%xmod)*(fpow(fac[on],xmod-2)%xmod)%xmod)*(fpow(fac[tw],xmod-2)%xmod))%xmod;
		ans+=num*2;
		ans%=xmod;
		//printf("%lld\n",num);
	}
	printf("%lld\n",ans);
    return 0;
}