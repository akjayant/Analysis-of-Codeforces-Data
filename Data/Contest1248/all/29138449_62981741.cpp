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
ll a[maxn];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll a1=0,a2=0;
	int x=n/2;
	for(int i=1;i<=x;i++){
		a1+=a[i];
		a2+=a[n-i+1];
	}
	if(n%2) a2+=a[n/2+1];
	ll dis=a2*a2+a1*a1;
	printf("%lld\n",dis);
}