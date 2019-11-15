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

const int MaxN=1e5+5;
const ll Mod=1e9+7;
ll f[MaxN],Ans=1;
char S[MaxN];

int main(){
	scanf("%s",S+1);
	int n=strlen(S+1);
	rep(i,1,n)if(S[i]=='m' or S[i]=='w')return not printf("0");
	f[0]=f[1]=1;
	rep(i,2,n)f[i]=(f[i-1]+f[i-2])%Mod;
	int Pos;
	rep(i,1,n){
		if(S[i]=='u' or S[i]=='n'){
			Pos=i;
			while(Pos<n and S[Pos+1]==S[i])++Pos;
			Ans=(Ans*f[Pos-i+1])%Mod;
			i=Pos;
		}
	}
	return not printf("%I64d",Ans);
}
