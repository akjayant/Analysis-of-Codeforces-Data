#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d,k;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		int cnt1=a/c,cnt2=b/d;
		if(a%c!=0)
			cnt1++;
		if(b%d!=0)
			cnt2++;
		if(cnt1+cnt2<=k)
			printf("%d %d\n",cnt1,cnt2);
		else
			printf("-1\n");
	}
}