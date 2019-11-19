#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100010;
const int INF = 0x3f3f3f3f;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,m;
		ll cnt1=0,cnt2=0,cnt3=0,cnt4=0;
		scanf("%d",&n);
		int x;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x%2) cnt1++;
			else cnt2++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&x);
			if(x%2) cnt3++;
			else cnt4++;
		}
		ll ans=0;
		ans=cnt1*cnt3+cnt2*cnt4;
		printf("%lld\n",ans);
	}
}