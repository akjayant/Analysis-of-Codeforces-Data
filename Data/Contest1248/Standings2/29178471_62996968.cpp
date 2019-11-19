#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500+10;
const ll P=1000000007;
int n,x,y,ans,re;
char s[MAXN];
int Cal(char* s,int n)
{
	static int LL[MAXN],RR[MAXN],LR[MAXN],RL[MAXN];
	int Cnt=0;
	for(int i=1;i<=n;i++)
	{
		LL[i]=LL[i-1];
		LR[i]=LR[i-1];
		if(s[i]=='(') ++LL[i];
		else 
		{
			if(LL[i]) --LL[i];
			else ++LR[i];
		}
	}
	for(int i=n;i;i--)
	{
		RR[i]=RR[i+1];
		RL[i]=RL[i+1];
		if(s[i]==')') ++RR[i];
		else 
		{
			if(RR[i]) --RR[i];
			else ++RL[i];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(RR[n-i+1]==0 && LL[n-i]==0 && RL[n-i+1]==LR[n-i])
			++Cnt;
	}
	return Cnt;
}

int main()
{
	scanf("%d%s",&n,s+1);
	for(int p=1;p<=n;p++)
		for(int q=p;q<=n;q++)
		{
			swap(s[p],s[q]);
			re=Cal(s,n);
			if(re>=ans) ans=re,x=p,y=q;
			swap(s[q],s[p]);
		}
	printf("%d\n%d %d",ans,x,y);
	return 0;
}
