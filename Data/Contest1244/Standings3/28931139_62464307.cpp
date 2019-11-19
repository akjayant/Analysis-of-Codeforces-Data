#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int x=(a+c-1)/c;
		int y=(b+d-1)/d;
		if(x+y>k)printf("-1\n");
		else printf("%d %d\n",x,y);
	}
	return 0;
}