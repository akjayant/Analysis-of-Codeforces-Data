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
char s[N];
int main ()
{
	// freopen (".in","r",stdin);
	// freopen (".out","w",stdout);
	int T; sc(T);
	while (T--)
	{
		int n; sc(n);
		scanf ("%s",s+1);
		int ans=n;
		for (int i=1; i<=n; i++)
			if (s[i]=='1') ans=max (ans,max (i*2,(n-i+1)*2));
		pr(ans);
	}

	return 0;
}
