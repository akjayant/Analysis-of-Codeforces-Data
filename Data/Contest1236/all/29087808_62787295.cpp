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

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int INF = 2147483600;
const int MAXN = 100010;
const LL Mod = 1000000007LL;

int N,M;

inline LL Pow(LL a,LL b){
	LL ret=1; for(;b;b>>=1,a=a*a%Mod) if(b&1) ret=ret*a%Mod; return ret;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),M=read();
	printf("%I64d\n",Pow(Pow(2,M)-1,N));
	return 0;
}
