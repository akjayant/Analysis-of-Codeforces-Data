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
const int mod=1e9+7;
int n,m;
ll a[100010];
int main(){
	scanf("%d%d",&n,&m);
	int k=max(n,m);
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=k;i++){
		a[i]=(a[i-1]+a[i-2])%mod;
	}
	ll ans=((a[n]+a[m]-1)*2ll+mod)%mod;
	printf("%lld\n",ans);
}