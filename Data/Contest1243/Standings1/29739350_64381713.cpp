#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
int n;
char s[10010],t[10010];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int main()
{
	int T=read();
	while (T--)
	{
		n=read();
		scanf("%s",s+1);
		scanf("%s",t+1);
		int cnt=0;
		rep(i,1,n) cnt+=(s[i]==t[i]);
		if (cnt==n) puts("Yes");
		else if (cnt==n-2)
		{
			int p1=0,p2=0;
			rep(i,1,n) 
				if (s[i]!=t[i]) 
				{
					if (!p1) p1=i;else p2=i;
				}
			if ((s[p1]==s[p2]) && (t[p1]==t[p2])) puts("Yes");
			else puts("No");
		}
		else puts("No");
	}
	return 0;
}

