#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int maxn = 100005;

int d[maxn],j[maxn];
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		ll dj=0,dou=0,jj=0,jou=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&d[i]);
			if(d[i]%2==1) dj++;
			else dou++;
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",&j[i]);
			if(j[i]%2==1) jj++;
			else jou++;
		}
		printf("%lld\n",dj*jj+dou*jou);
	}
	return 0;
}