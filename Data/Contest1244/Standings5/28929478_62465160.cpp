#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d,k;scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int aa=(a+c-1)/c,bb=(b+d-1)/d;
		if(aa+bb <= k) printf("%d %d\n",aa,bb);
		else printf("-1\n");
	}
 } 