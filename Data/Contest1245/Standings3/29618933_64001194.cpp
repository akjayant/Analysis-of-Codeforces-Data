#include<algorithm>
#include<iostream>
#include<complex>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<ctime>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define N 10039
#define mod 20070831
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int t,n,A,B,C;
char ch,now,ans[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&A,&B,&C);
		now=0;
		for(int a=1;a<=n;a++)
		{
			scanf(" %c",&ch);
			ans[a]=0;
			if(ch=='R' && B) B--,now++,ans[a]='P';
			if(ch=='P' && C) C--,now++,ans[a]='S';
			if(ch=='S' && A) A--,now++,ans[a]='R';
		}
		if(now<(n+1)/2) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int a=1;a<=n;a++)
			{
				if(ans[a]) cout<<ans[a];
				else if(A) A--,cout<<'R';
				else if(B) B--,cout<<'P';
				else C--,cout<<'S';
			}
			cout<<endl;
		}
	}
	return 0;
}
/*Kamii_Sinogi*/