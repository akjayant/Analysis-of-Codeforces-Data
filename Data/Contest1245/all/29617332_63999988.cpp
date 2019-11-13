#include<bits/stdc++.h>

using namespace std;
const int N=11000;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int T;
int n,a,b,c;
char s[N];
char t[N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%d %d %d",&a,&b,&c);
		scanf("%s",s+1);
		t[n+1]=0;
		int num=0;
		for (int i=1;i<=n;i++)
			t[i]=0;
		for (int i=1;i<=n;i++)
			if (s[i]=='R')
			{
				if (b) b--,num++,t[i]='P';
			}
			else if (s[i]=='P')
			{
				if (c) c--,num++,t[i]='S';
			}
			else
			{
				if (a) a--,num++,t[i]='R';
			}
		if (num>=(n+1)/2)
		{
			for (int i=1;i<=n;i++)
				if (t[i]==0)
				{
					if (a) a--,t[i]='R';
					else if (b) b--,t[i]='P';
					else c--,t[i]='S';
				}
			printf("YES\n");
			printf("%s\n",t+1);
		}
		else printf("NO\n");
	}
	return 0;
}