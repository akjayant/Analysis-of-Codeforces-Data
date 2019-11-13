#include<bits/stdc++.h>
#define maxl 300010

using namespace std;

const int mod=1e9+7;

int n,m,ans;
int f[maxl];
char s[maxl];


inline void prework()
{
	scanf("%s",s+1);
	n=strlen(s+1);
}

inline void mainwork()
{
	
	f[0]=1;f[1]=1;ans=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1];
		if(s[i]=='u' && s[i-1]=='u')
			f[i]=(f[i]+f[i-2])%mod;
		if(s[i]=='n' && s[i-1]=='n')
			f[i]=(f[i]+f[i-2])%mod;
		if(s[i]=='w')
			ans=0;
		if(s[i]=='m')
			ans=0;
	}
	if(s[1]=='w' || s[1]=='m')
		ans=0;
}

inline void print()
{
	if(ans)
		printf("%d",f[n]);
	else
		puts("0");
}

int main()
{
	int t=1;
	//scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{ 
		prework();
		mainwork();
		print();
	}
	return 0;
}
