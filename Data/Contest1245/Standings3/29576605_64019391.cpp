#include<bits/stdc++.h>
#define gc getchar
#define re register
#define rep(i,s,t) for(re int i=s;i<=t;++i)
#define reb(i,s,t) for(re int i=s;i>=t;--i)

template<class T>inline void Readin(T &X){
	X=0;
	register bool F=false;
	register char C=gc();
	while(C<'0' or C>'9'){if(C=='-')F=true;C=gc();}
	while(C<='9' and C>='0')X=(X<<1)+(X<<3)+(C&15),C=gc();
	if(F)X=-X;
}
template<class T>inline void Prt(T X){
	if(X<0)putchar('-'),X=-X;
	if(X>9)Prt(X/10);
	putchar(X%10+'0');
}

using namespace std;
typedef long long ll;

const int MaxN=2005;
int n,x[MaxN],y[MaxN],c[MaxN],k[MaxN],Cnt,fa[MaxN],Ansx[MaxN],Ansy[MaxN],cnt_edge,cnt_p;
bool blt[MaxN];
ll Ans;
struct Edge{
	int x,y;
	ll Cost;
	inline bool operator < (const Edge ano) const{
		return Cost<ano.Cost;
	}
}e[MaxN*MaxN+MaxN];

inline int gf(int x){return fa[x]=x==fa[x]?x:gf(fa[x]);}
int main(){
	Readin(n);
	rep(i,1,n)Readin(x[i]),Readin(y[i]),fa[i]=i;
	rep(i,1,n)Readin(c[i]),e[++Cnt].Cost=c[i],e[Cnt].x=0,e[Cnt].y=i;
	rep(i,1,n)Readin(k[i]);
	rep(i,1,n-1)rep(j,i+1,n){
		e[++Cnt].Cost=1ll*(k[i]+k[j])*(ll)(abs(x[i]-x[j])+abs(y[i]-y[j]));
		e[Cnt].x=i,e[Cnt].y=j;
	}
	sort(e+1,e+1+Cnt);
	re int x,y;
	rep(i,1,Cnt){
		x=gf(e[i].x),y=gf(e[i].y);
		if(x==y)continue;
		Ans+=e[i].Cost;
		if(e[i].x)Ansx[++cnt_edge]=e[i].x,Ansy[cnt_edge]=e[i].y;
		else ++cnt_p,blt[e[i].y]=true;
		fa[y]=x;
	}
	Prt(Ans),putchar('\n');
	Prt(cnt_p),putchar('\n');
	rep(i,1,n)if(blt[i])Prt(i),putchar(' ');
	putchar('\n');
	Prt(cnt_edge);
	putchar('\n');
	rep(i,1,cnt_edge)Prt(Ansx[i]),putchar(' '),Prt(Ansy[i]),putchar('\n');
	return 0;
}
