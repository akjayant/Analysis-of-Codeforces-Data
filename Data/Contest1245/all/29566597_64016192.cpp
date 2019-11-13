#include<bits/stdc++.h>
#define maxl 300010

using namespace std;

int n,m,ans;
int a,b,c;
char s[maxl],t[maxl];

inline void prework()
{
	scanf("%d%d%d%d",&n,&a,&b,&c);
	scanf("%s",s+1);
}

inline void mainwork()
{
	ans=0;
	for(int i=1;i<=n;i++)
		t[i]=0;
	for(int i=1;i<=n && a>0;i++)
	if(s[i]=='S')
		t[i]='R',ans++,a--;
		
	for(int i=1;i<=n && b>0;i++)
	if(s[i]=='R')
		t[i]='P',ans++,b--;
		
	for(int i=1;i<=n && c>0;i++)
	if(s[i]=='P')
		t[i]='S',ans++,c--;
	
	for(int i=1;i<=n;i++)
	if(t[i]==0)
	{
		if(a>0)
			t[i]='R',a--;
		else if(b>0)
			t[i]='P',b--;
		else
			t[i]='S',c--;
	}
}

inline void print()
{
	if(ans>=((n+1)/2))
	{
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%c",t[i]);
		puts("");
	}
	else
		puts("NO");
}

int main()
{
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{ 
		prework();
		mainwork();
		print();
	}
	return 0;
}
