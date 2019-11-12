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
int main(){
	int T=read();
	while(T--){
		int a=read(),b=read(),c=read(),ans=0;
		for(int j=0;j<=100;j++)
			for(int k=0;k<=100;k++)
				if(j<=a&&2*k<=c&&2*j+k<=b)
					ans=max(ans,j+2*j+k+2*k);
		printf("%d\n",ans);
	}
    return 0;
}