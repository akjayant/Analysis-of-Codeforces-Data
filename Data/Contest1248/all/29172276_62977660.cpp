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
int p[MAXN+5],q[MAXN+5];
int main(){
	int T=read();
	while(T--){
		int n=read(),cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			p[i]=read();
			if(p[i]&1) cnt1++;
		}
		int m=read();
		for(int i=1;i<=m;i++){
			q[i]=read();
			if(q[i]&1) cnt2++;
		}
		printf("%lld\n",1ll*cnt1*cnt2+1ll*(n-cnt1)*(m-cnt2));
	}
	return 0;
}