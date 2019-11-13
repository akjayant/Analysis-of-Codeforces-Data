#include<bits/stdc++.h>
typedef int LL;
const LL maxn=1e6+9,mod=1e9+7;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3)+(x<<1)+c-'0'; c=getchar();
	}
	return x*f;
}
LL f[maxn][2];
char s[maxn];
LL Calc(LL l,LL r){
	return 1ll*(f[r-l+1][0]+f[r-l+1][1])%mod;
}
int main(){
	scanf(" %s",s+1);
	LL n(strlen(s+1));
	f[0][0]=f[1][0]=1;
	for(LL i=2;i<=100000;++i){
		f[i][0]=1ll*(f[i-1][0]+f[i-1][1])%mod;
		f[i][1]=1ll*(f[i-2][0]+f[i-2][1])%mod;
	}
	LL ans(1),fir(0);
	for(LL i=1;i<=n;++i){
		if(s[i]!='u'){
			if(s[i-1]=='u'){
//			printf("(%d,%d)\n",fir,i-1);
			ans=1ll*ans*Calc(fir,i-1)%mod;
				
			}
			fir=0;
		}else if(!fir) fir=i;
	}
	if(s[n]=='u') ans=1ll*ans*Calc(fir,n)%mod;
	fir=0;
	for(LL i=1;i<=n;++i){
		if(s[i]!='n'){
			if(s[i-1]=='n'){
			ans=1ll*ans*Calc(fir,i-1)%mod;
			}
			fir=0;
		}else if(!fir) fir=i;
	}
	if(s[n]=='n') ans=1ll*ans*Calc(fir,n)%mod;
	for(LL i=1;i<=n;++i){
		if(s[i]=='m' || s[i]=='w'){
			puts("0");
			return 0;
		}
	}
	printf("%d\n",ans);
	return 0;
}