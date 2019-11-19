#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() 
{
	int n,p,w,d;
	scanf("%I64d%I64d%I64d%I64d",&n,&p,&w,&d);
	for(int i=p/w+1;i>=max(0ll,p/w-1000000);i--)
	{
		int y=(p-i*w)/d;
		if(y<0)
			continue;
		if(i+y<=n&&i*w+y*d==p)
		{
			printf("%I64d %I64d %I64d",i,y,n-i-y);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
/*
30 60 3 2
*/