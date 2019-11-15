#include<bits/stdc++.h>
#define FOR(i,a,b) for (register int i=(a);i<=(b);i++)
#define For(i,a,b) for (register int i=(a);i>=(b);i--)
#define mem(i,j) memset(i,j,sizeof(i))
#define GO(u) for (register int j=f[u];j!=-1;j=nxt[j])
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define MP make_pair
using namespace std;
typedef long long ll;
const int N=5050;
int n,a[N][N],pt=0;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return f*x;
}
inline void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
int main()
{
	n=read();
	FOR(i,1,n)
	{
		if (i&1) For(j,n,1) a[j][i]=++pt;
		else FOR(j,1,n) a[j][i]=++pt;
	}
	FOR(i,1,n)
	{
		FOR(j,1,n) write(a[i][j]),putchar(' ');
		putchar('\n');
	}
	return 0;
}
