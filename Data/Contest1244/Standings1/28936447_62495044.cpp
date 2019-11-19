#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

#define LL long long
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline LL read(){
	LL x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const LL INF = 2147483600;
const LL MAXN = 100010;

LL N,K;
LL a[MAXN+1],b[MAXN+1];

inline bool check(LL ln){
	LL suml=0,sumr=0;
	for(LL i=1;i<=N;i++) sumr+=b[i]; LL nw=0;
	for(LL i=1;i<=N;i++){
		while(nw<N&&b[nw+1]<=ln+b[i]) sumr-=b[nw+1],++nw;
		suml+=b[i]; if(i*b[i]-suml+sumr-(ln+b[i])*(N-nw)<=K) return true;
	} suml=0;	
	for(LL i=1;i<=N;i++) suml+=b[i]; nw=N+1;
	sumr=0;
	for(LL i=N;i>=1;i--){
		while(nw>1&&b[nw-1]>=b[i]-ln) suml-=b[nw-1],--nw;
		sumr+=b[i]; if((nw-1)*(b[i]-ln)-suml+sumr-b[i]*(N-i+1)<=K) return true;
	} 
	return false;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),K=read();
	for(LL i=1;i<=N;i++) a[i]=read(),b[i]=a[i];
	sort(b+1,b+N+1);
	LL l=0,r=1e9; LL ans=0;
	while(l<=r){
		LL mid=(l+r)>>1LL;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	} cout<<ans<<endl;
	return 0;
}
