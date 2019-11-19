#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		int pro=(a-1)/c+1,pre=(b-1)/d+1;
		if(pro+pre>e) printf("-1\n"); else printf("%d %d\n",pro,pre);
	}
	return 0;
}