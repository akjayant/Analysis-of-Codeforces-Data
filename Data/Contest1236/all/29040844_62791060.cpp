#include<set>
#include<map>
#include<stack>
#include<ctime>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int read(){
	bool f=0;int x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return !f?x:-x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
#define Mod int(1e9+7)
int Pow(LL x,LL y){
	int ret=1;
	while(y){
		if(y&1) ret=1ll*ret*x%Mod;
		x=1ll*x*x%Mod,y>>=1;
	}
	return ret;
}
int main(){
	int n=read(),m=read();
	printf("%d\n",((Pow(Pow(2,m)-1,n)))%Mod+Mod%Mod);
    return 0;
}