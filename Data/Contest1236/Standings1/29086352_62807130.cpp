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
const int M=1e5+5;
int n,m,k,U,D,L,R;
vector<int>X[M],Y[M];
int rx[]={-1,0,1,0};
int ry[]={0,1,0,-1};
int solve(int op,int x,int y){
	if(op==0){
		int sz=Y[y].size();
		for(int i=sz-1;i>=0;i--)if(Y[y][i]<x)return x-max(U,Y[y][i])-1;
	}
	if(op==1){
		int sz=X[x].size();
		for(int i=0;i<sz;i++)if(X[x][i]>y)return min(R,X[x][i])-y-1;
	}
	if(op==2){
		int sz=Y[y].size();
		for(int i=0;i<sz;i++)if(Y[y][i]>x)return min(D,Y[y][i])-x-1;
	}
	if(op==3){
		int sz=X[x].size();
		for(int i=sz-1;i>=0;i--)if(X[x][i]<y)return y-max(L,X[x][i])-1;
	}
	return -1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("jiedai.in","r",stdin);
//	freopen("jiedai.out","w",stdout);
#endif
	rd(n),rd(m),rd(k);
	for(int i=1;i<=n;i++)X[i].push_back(0),X[i].push_back(m+1);
	for(int i=1;i<=m;i++)Y[i].push_back(0),Y[i].push_back(n+1);
	for(int i=1;i<=k;i++){
		int x,y;
		rd(x),rd(y);
		X[x].push_back(y);
		Y[y].push_back(x);
		if(x==1&&y==1){
			puts("No");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)sort(X[i].begin(),X[i].end());
	for(int i=1;i<=m;i++)sort(Y[i].begin(),Y[i].end());
	int op=1,x=1,y=1;
	ll cnt=1;
	U=0,D=n+1,L=0,R=m+1;
	while(1){
		int res=solve(op,x,y);
		if(res==0)op=(op+1)%4,res=solve(op,x,y);
//		printf("op=%d  x=%d  y=%d  -->  %d\n",op,x,y,res);
		if(res==0)break;
		x=x+res*rx[op];
		y=y+res*ry[op];
		cnt+=res;
		if(op==0)L=y;
		if(op==1)U=x;
		if(op==2)R=y;
		if(op==3)D=x;
	}
	puts(cnt+k==1ll*n*m?"Yes":"No");
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<X[i].size();j++)printf("%d ",X[i][j]);
//		puts("");
//	}
//	printf("%lld\n",cnt);
	return (0-0);
}