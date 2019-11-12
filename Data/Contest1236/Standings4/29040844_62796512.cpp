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
#define MAXN 300
#define INF 0x3f3f3f3f
#define Mod int(1e9+7)
int a[MAXN+5][MAXN+5];
int main(){
	int n=read(),cnt=0;
	for(int i=1;i<=n;i++){
		if(i&1)
			for(int j=1;j<=n;j++)
				a[i][j]=++cnt;
		else for(int j=n;j>=1;j--)
			a[i][j]=++cnt;
	}
	for(int j=1;j<=n;j++,puts(""))
		for(int i=1;i<=n;i++)
			printf("%d ",a[i][j]);
    return 0;
}