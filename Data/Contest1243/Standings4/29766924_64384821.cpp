#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<deque>
#include<set>
#define inf 1e9
#define eps 1e-6
#define N 10010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int T;
char s[N],t[N];
int n,L,R;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s%s",s+1,t+1);
		L=0,R=n+1;
		for(register int i=1;i<=n;i++)
		{
			if(s[i]==t[i])L=i;
			else break;
		}
		if(L==n){printf("Yes\n");continue;}
		for(register int i=n;i>=1;i--)
		{
			if(s[i]==t[i])R=i;
			else break;
		}
		if(R==L+2){printf("No\n");continue;}
		int flag=0;
		for(register int i=L+2;i<=R-2;i++)
		{
			if(s[i]!=t[i]){flag=1;break;}
		}
		if(flag){printf("No\n");continue;}
		if(s[L+1]!=s[R-1]||t[L+1]!=t[R-1]){printf("No\n");continue;}
		printf("Yes\n");
	}
	return 0;
}
/*
2
4
zbaz
zabz
4
zbbz
zaaz
*/
