#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if((a+c-1)/c+(b+d-1)/d<=k) printf("%d %d\n",(a+c-1)/c,(b+d-1)/d);
		else printf("-1\n");
	}
	return 0;
} 
