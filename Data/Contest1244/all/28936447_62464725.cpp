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

int T; 
int A,B,C,D,K;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--){
		int ansx=-1,ansy=-1;
		A=read(),B=read(),C=read(),D=read(),K=read();
		for(int i=0;i<=K;i++){
			int x=i,y=K-i;
			if(x*C>=A&&y*D>=B){
				ansx=x; ansy=y;
				break;
			}
		} if(ansx==-1){
			puts("-1");
		} else printf("%d %d\n",ansx,ansy);
	} 
	return 0;
}
