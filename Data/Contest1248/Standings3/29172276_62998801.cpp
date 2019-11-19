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
LL f[MAXN+5][2];
int main(){//f[i][0|1]:前i个数，最后一个数和之前是否相同方案数
	int n=read(),m=read();
	f[1][0]=2;
	for(int i=2;i<=max(n,m);i++)
		f[i][0]=(f[i-1][1]+f[i-1][0])%Mod,f[i][1]=f[i-1][0];
	printf("%lld\n",((f[n][0]+f[n][1]+f[m][0]+f[m][1]-2)%Mod+Mod)%Mod);
	return 0;
}