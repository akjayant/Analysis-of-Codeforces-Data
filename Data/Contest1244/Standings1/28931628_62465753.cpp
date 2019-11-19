#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int read(){
	int f=0,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
int main(){
	int T=read();
	while(T--){
		int a=read(),b=read(),c=read(),d=read(),k=read();
		int x=(a+c-1)/c,y=(b+d-1)/d;
		if(x+y>k) puts("-1");
		else printf("%d %d\n",x,y);
	}
	return 0;
}
