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

int T; int N; char str[MAXN+1];

inline void solve(){
	int mn=INF,mx=-INF;
	int sum=0;
	for(int i=1;i<=N;i++) {
		sum+=(str[i]=='1');
		if(str[i]=='1'){
			mn=min(mn,i);
			mx=max(mx,i);
		}
	}
	if(!sum){
		cout<<N<<endl;
		return ;
	}
	cout<<max(mx*2,(N-mn+1)*2)<<endl;
	return ;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--){
		N=read(); scanf("%s",str+1);
		solve();
	}
	return 0;
}
