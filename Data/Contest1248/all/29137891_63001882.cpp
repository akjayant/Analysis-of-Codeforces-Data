#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
char s[100001];
int p[100001];
signed main()
{
	int n;
	scanf("%d",&n);
	cin>>s+1;
	int sum=0,a1=1,a2=1;
	for(int i=1;i<=n;i++)
		sum+=s[i]==')';
	if(n%2!=0||sum!=n/2)
	{
		printf("0\n1 1\n");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			swap(s[i],s[j]);
			int tot=0,st=1,res=0,las=0;
			for(int k=1;k<=n;k++)
			{
				if(s[k]==')')
					tot--;
				else
					tot++;
				if(tot<las)
					st=k+1,las=tot;
			}
			if(st==n+1)st=1;
			for(int k=st;k<=n;k++)
			{
				if(s[k]==')')
					tot--;
				else
					tot++;
				if(tot<0)
					res=-inf;
				res+=tot==0;
			}
			for(int k=1;k<st;k++)
			{
				if(s[k]==')')
					tot--;
				else
					tot++;
				if(tot<0)
					res=-inf;
				res+=tot==0;
			}
			if(res>ans)
			{
				ans=res;
				a1=i,a2=j;
			}
			swap(s[i],s[j]);
		}
	}
	printf("%d\n%d %d\n",ans,a1,a2);
    return 0;
}
/*
10
)))))(((((
*/