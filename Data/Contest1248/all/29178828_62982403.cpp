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
const int maxn = 1e6 + 10;
ll a[maxn];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	int len=(n+1)/2;
	ll ans1=0,ans2=0;
	for(int i=1;i<=len;i++){
		ans1+=a[i];
	}
	for(int i=len+1;i<=n;i++){
		ans2+=a[i];
	}
	ll ans=ans1*ans1+ans2*ans2;
	printf("%lld\n",ans);
	return 0;
}
