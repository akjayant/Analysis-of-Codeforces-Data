#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//const int maxn=1000000000+7;
typedef long long ll;
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		ll od1=0,ev1=0,od2=0,ev2=0;
		scanf("%d",&n);
		ll x;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
			if(x&1)
				od1++;
			else ev1++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%lld",&x);
			if(x&1)
				od2++;
			else ev2++;
		}
		ll ans=0;
		ans=ans+od1*od2+ev1*ev2;
		printf("%lld\n",ans);
	}
return 0;
}