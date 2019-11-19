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

const int N=1005;
int T,n,ls,rs,Cnt;
char S[N];

int main(){
	Readin(T);
	for(;T--;){
		Readin(n);
		Cnt=rs=0,ls=n+1;
		scanf("%s",S+1);
		rep(i,1,n)if(S[i]-'0'){if(!rs)ls=rs=i,Cnt=1;else rs=i,++Cnt;}
		printf("%d\n",max(n+Cnt,2*max(n-ls+1,rs)));
	}
	return 0;
}
