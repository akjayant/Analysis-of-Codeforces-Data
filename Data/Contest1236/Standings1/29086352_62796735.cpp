#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
const int M=305;
int n,A[M][M];

int main(){
#ifndef ONLINE_JUDGE
//	freopen("jiedai.in","r",stdin);
//	freopen("jiedai.out","w",stdout);
#endif
	rd(n);
	int x=1,y=1,tot=0,up=0;
	while(1){
		A[x][y]=++tot;
		if(y>n)break;
		if(up){
			x--;
			if(x==0)up=0,x=1,y++;
		}
		else{
			x++;
			if(x==n+1)up=1,x=n,y++;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",A[i][j],j==n?'\n':' ');
	return (0-0);
}