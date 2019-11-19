//good luck
# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>
# include <ctime>
# include <map>

#define LL long long
#define maxn int(1e5+5)
#define inf (int)1e9
#define is(a) (a>='0'&&a<='9')
#define iabs(a) ((a)>0?(a):(-a))
#define imax(a,b) ((a)>(b)?(a):(b))
#define imin(a,b) ((a)<(b)?(a):(b))
 
using namespace std;

LL N,M,x,y,a[maxn];

inline void read(LL &x)
{
  x=0;bool f=0;char ch=getchar();
  for (;!is(ch);ch=getchar()) f|=ch=='-';
  for (;is(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
  x=f?-x:x;
}

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	read(N);
	for (int i = 1; i <= N; ++i) read(a[i]);
	M = N>>1;
	sort(a+1,a+1+N);
	for (int i = 1; i <= M; ++i) x+=a[i];
	for (int i = M+1; i <= N; ++i) y+=a[i];
	cout << x*x+y*y <<endl;
    return 0;
}	
