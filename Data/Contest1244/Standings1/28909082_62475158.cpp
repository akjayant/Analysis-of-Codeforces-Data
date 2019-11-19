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

ll n,p,d,w;

int main(){
	Readin(n),Readin(p),Readin(w),Readin(d);
	if(!p)return not printf("0 0 %I64d",n);
	ll x,xx,y,z,nn;
	xx=x=p/w;
	if(x>n)return not printf("-1");
	nn=p%w;
	if(nn%d==0){
		y=nn/d;
		if(x+y>n)return not printf("-1");
		return not printf("%I64d %I64d %I64d",x,y,n-x-y);
	}
	rep(i,1,min(d,xx)){
		--x;
		nn+=w;
		if(nn%d==0){
			y=nn/d;
			if(x+y>n)return not printf("-1");
			return not printf("%I64d %I64d %I64d",x,y,n-x-y);
		}
	}
	return not printf("-1");
}
