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

int T,n,a,b,c,w,A[110],aa,bb,cc;
char S[110],S2[110];

int main(){
	Readin(T);
	for(;T--;){
		Readin(n),Readin(a),Readin(b),Readin(c);
		w=(n+1)/2,aa=bb=cc=0;
		scanf("%s",S+1);
		rep(i,1,n)if(S[i]=='S')++aa;else if(S[i]=='P')++cc;else ++bb;
		if(w<=min(aa,a)+min(b,bb)+min(c,cc)){
			puts("YES");
			memset(S2,'\0',sizeof S2);
			rep(i,1,n)if(S[i]=='S'&&a)--a,S2[i]='R';else if(S[i]=='P'&&c)--c,S2[i]='S';else if(S[i]=='R'&&b)--b,S2[i]='P';
			rep(i,1,n)if(S2[i]=='\0'){
				if(a)S2[i]='R',--a;
				else if(b)S2[i]='P',--b;
				else if(c)S2[i]='S',--c;
			}
			rep(i,1,n)putchar(S2[i]);
			putchar('\n');
		}
		else puts("NO");
	}
	return 0;
}
