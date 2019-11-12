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

int N;
int a[510][510];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read();
	for(int j=1;j<=N;j++){
		for(int i=1;i<=N;i++)
			if(j&1){
				a[i][j]=i+(j-1)*N;
			} else a[i][j]=N-i+1+(j-1)*N;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
