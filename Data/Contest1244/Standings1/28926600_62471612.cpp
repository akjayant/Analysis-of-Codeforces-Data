#include <algorithm>
// #include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
// #include <bitset>
const int oo=2139063143;
const int N=1010000;
const int P=1000000007;
using namespace std;
typedef long long LL;
typedef double db;
#define pritnf printf
//char buf[1<<24],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void sc (T &x)
{
    x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
}
template <typename T>
inline void print (T x)
{
	if (x< 0) putchar('-'),x=-x;
	if (x>=10) print(x/10);
	putchar(x%10+'0');
}
template <typename T>
inline void pr (T x) { print(x),putchar('\n'); }
#define pii pair<LL,LL>
#define fi first
#define se second
#define mp make_pair
pii b[N];
LL a[N];
int main ()
{
	// freopen (".in","r",stdin);
	// freopen (".out","w",stdout);
	LL n; sc(n);
	LL m; sc(m);
	for (int i=1; i<=n; i++)
		sc(a[i]);
	sort (a+1,a+n+1);
	LL cur=0,tot=0;
	for (int i=1; i<=n+1; i++)
	{
		if (a[i-1]&&a[i]!=a[i-1]) b[++tot]=mp(a[i-1],cur),cur=0;
		++cur;
	}
	n=tot;
	// for (int i=1; i<=n; i++)
	// 	printf ("%d %d\n",b[i].fi,b[i].se);
	LL l=1,r=n;
	while (m&&l!=r)
	{
		LL g1=b[l].se;
		LL g2=b[r].se;
		if (g1<=g2)
		{
			LL d=min (b[l+1].fi-b[l].fi,m/b[l].se);
			if (!d) break;
			b[l].fi+=d;
			m-=d*b[l].se;
			if (b[l].fi==b[l+1].fi) b[l+1].se+=b[l].se,++l;
		}
		else
		{
			LL d=min (b[r].fi-b[r-1].fi,m/b[r].se);
			if (!d) break;
			b[r].fi-=d;
			m-=d*b[r].se;
			if (b[r].fi==b[r-1].fi) b[r-1].se+=b[r].se,--r;
		}
	}
	pr(b[r].fi-b[l].fi);

	return 0;
}
