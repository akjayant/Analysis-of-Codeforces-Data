#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#include <cstdlib>
#define inf 0x3f3f3f3f
#define LL long long 
#define inf64 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,m,even1=0,even2=0,odd1=0,odd2=0;
		scanf("%lld",&n);
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			if(x&1) odd1++;
			else even1++;
		}
		scanf("%lld",&m);
		for(int i=0;i<m;i++){
			int x;
			scanf("%d",&x);
			if(x&1) odd2++;
			else even2++;
		}
		ll ans=odd1*1ll*odd2+even1*1ll*even2;
		printf("%lld\n",ans);
	}
	return 0;
}
