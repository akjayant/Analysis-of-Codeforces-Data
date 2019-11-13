#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
char s[maxn],t[maxn];
int k,n;
int main()
{
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		int cc=0;
		char a,b,c,d;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==t[i]) continue;
			if(cc==0) a=s[i],b=t[i],cc++;
			else if(cc==1)
			{
				c=s[i],d=t[i];
				cc++;
			}
			else
			{
				c++;break;
			}
		}
		if(cc==2&&a==c&&b==d)
		{
			printf("YES\n");
		}
		else 
		printf("NO\n");
	}
	return 0;
}