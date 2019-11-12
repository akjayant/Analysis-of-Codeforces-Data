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

int T; int A,B,C; 

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--){
		A=read(),B=read(),C=read(); int ans=0;
		for(int chsa=0;chsa<=min(A,B/2);chsa++){
			ans=max(ans,chsa*3+min(B-chsa*2,C/2)*3);
		} printf("%d\n",ans);
	}
	return 0;
}
