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

int main(){
	int t;
	Readin(t);
	for(;t--;){
		int a,b,c,d,k,aa,bb;
		Readin(a),Readin(b),Readin(c),Readin(d),Readin(k);
		aa=a/c+(a%c>0),bb=b/d+(b%d>0);
		if(aa+bb>k){puts("-1");continue;}
		printf("%d %d\n",aa,bb);
	}
	return 0;
}
