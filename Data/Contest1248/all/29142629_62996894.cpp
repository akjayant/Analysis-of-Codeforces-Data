#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
const int MAXN=100000;
const long long ONE=1;
const int MOD=1000000007;
int N,M;
long long f[MAXN+5],e[MAXN+5];
long long C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return (f[x]*((e[y]*e[x-y])%MOD))%MOD;
}
long long Ans;
LL quick_Pow(LL x,LL y){
	if(y==0)return 1;
	if(y==1)return x;
	if(y%2)return (x*quick_Pow((x*x)%MOD,y/2))%MOD;
	return quick_Pow((x*x)%MOD,y/2);
}
void Prepare(){
	f[0]=e[0]=1;
	for(int i=1;i<=MAXN;i++){
		f[i]=(f[i-1]*i)%MOD;
		e[i]=quick_Pow(f[i],MOD-2);
	}
}
void Solve(){
	for(int i=0;i<=M;i++){
		/*i==x==y*/
		Ans=(Ans+2*C(2*i,M-2*i))%MOD;
		/*i==x==y-1*/
		Ans=(Ans+C(2*i+1,M-2*i-1))%MOD;
		/*i==x==y+1*/
		Ans=(Ans+C(2*i-1,M-2*i+1))%MOD;
	}
}
int main(){
	Prepare();
	scanf("%d%d",&N,&M);
	Solve();swap(N,M);Solve();
	printf("%lld\n",(Ans-2+MOD)%MOD);
}