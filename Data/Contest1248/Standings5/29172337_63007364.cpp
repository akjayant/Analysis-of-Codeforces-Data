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
#define is(a) (a>='0'&&a<='9')
#define iabs(a) ((a)>0?(a):(-a))
#define imax(a,b) ((a)>(b)?(a):(b))
#define imin(a,b) ((a)<(b)?(a):(b))
 
using namespace std;

const LL INF=-1;

struct data{LL x;}t[maxn<<2];

LL N,p,T,ans[maxn],d[maxn];
LL L,R,n,m,P;

inline void read(LL &x)
{
  x=0;bool f=0;char ch=getchar();
  for (;!is(ch);ch=getchar()) f|=ch=='-';
  for (;is(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
  x=f?-x:x;
}

inline LL cmin(LL x,LL y){return x==-1&&y==-1?-1:(x==-1?y:(y==-1?x:imin(x,y)));}

inline void up(int ro)
{
	t[ro].x = cmin(t[ro<<1].x,t[ro<<1|1].x);
}

inline void Build(int ro,int L,int R)
{
	if (L==R) {t[ro].x=d[L];return;}
	int Mid=(L+R)>>1;
	Build(ro<<1,L,Mid);
	Build(ro<<1|1,Mid+1,R);
	up(ro);
}

inline void update(int ro,int L,int R,int x,int val)
{
	if (x<L||x>R) return;
	if (L==R) {t[ro].x=val;return;}
	int Mid=(L+R)>>1;
	update(ro<<1,L,Mid,x,val);
	update(ro<<1|1,Mid+1,R,x,val);
	up(ro);
}

inline LL query(int ro,int L,int R,int li,int ri)
{
	if (ri<L||li>R) return -1;
	if (li<=L&&R<=ri) return t[ro].x;
	int Mid=(L+R)>>1;
	LL x=query(ro<<1,L,Mid,li,ri);
	LL y=query(ro<<1|1,Mid+1,R,li,ri);
	return cmin(x,y);
}

bool check(int x)
{
	LL f=query(1,1,N,1,x);
	return (f!=-1)&&f<=T;
}

bool check1(int x)
{
	LL f=query(1,1,N,1,x);
	return (f!=-1)&&f<=m;
}

void work()
{
	LL f=query(1,1,N,1,R);
	if (f!=-1&&f<=T) P=1,m=query(1,1,N,1,R);
}

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	read(N);read(p);
	for (int i = 1; i <= N; ++i) read(d[i]);
	Build(1,1,N);
	for (int i = 1; i <= N; ++i)
	{
		if (P)
		{
			L=1;R=N;
			while (L<R)
			{
				int Mid = (L+R)>>1;
				if (check1(Mid)) R=Mid;
				else 			L=Mid+1;
			}
		}
		else 
		{
			T=imax(T,query(1,1,N,1,N));
			L=1;R=N;
			while (L<R)
			{
				int Mid = (L+R)>>1;
				if (check(Mid)) R=Mid;
				else 			L=Mid+1;
			}	
		}
		
		ans[R]=T+p;
		T+=p;
		update(1,1,N,R,-1);
		P=0;
		work();
	}
	for (int i = 1; i <= N; ++i) printf("%I64d ",ans[i]);
    return 0;
}	
