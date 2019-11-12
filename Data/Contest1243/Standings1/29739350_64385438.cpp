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
int n,vis[100],a[30];
char s[100],t[100];
vector<pii> ans;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

bool same()
{
	rep(i,1,n) vis[i]=(s[i]==t[i]);
	rep(i,1,n) if (!vis[i]) return 0;
	return 1;
}

int main()
{
	int T=read();
	while (T--)
	{
		n=read();
		scanf("%s",s+1);
		scanf("%s",t+1);
		rep(i,0,25) a[i]=0;
		rep(i,1,n) a[s[i]-'a']++;
		rep(i,1,n) a[t[i]-'a']++;
		int ok=1;
		rep(i,0,25)
			if (a[i]&1) {puts("No");ok=0;break;}
		if (ok)
		{
			puts("Yes");ans.clear();
			while (1)
			{
				if (same()) break;
				int ok=0;
				rep(i,1,n) 
				{
					if (ok) break;
					rep(j,i+1,n)
					{
						if ((!vis[i]) && (!vis[j]) && (s[i]==s[j]))
						{
							ans.push_back(make_pair(j,i));
							swap(s[j],t[i]);ok=1;break;
						}
					}
				}
				if (!ok)
				{
					rep(i,1,n) 
					{
						if (ok) break;
						rep(j,i+1,n)
						{
							if ((!vis[i]) && (!vis[j]) && (t[i]==t[j]))
							{
								ans.push_back(make_pair(j,i));
								swap(s[j],t[i]);ok=1;break;
							}
						}
					}
				}
				if (!ok)
				{
					rep(i,1,n) 
					{
						if (ok) break;
						rep(j,i+1,n)
						{
							if ((!vis[i]) && (!vis[j]) && (s[i]==t[j]))
							{
								ans.push_back(make_pair(i,i));ans.push_back(make_pair(i,j));
								swap(s[i],t[i]);swap(s[i],t[j]);ok=1;break;
							}
						}
					}
				}
			}
			int len=ans.size();
			printf("%d\n",len);
			rep(i,0,len-1) printf("%d %d\n",ans[i].fir,ans[i].sec);
		}
	}
	return 0;
}
					

