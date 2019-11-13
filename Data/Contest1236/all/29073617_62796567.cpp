#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof((a)))

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int MN = 3e5 + 5;
const int P = 1e9 + 7;

int qpow(ll a,int b){
	ll ans=1;
	for(;b;b>>=1,a=a*a%P)
		if(b&1) ans=ans*a%P;
return ans;}

inline void solve(){
	ll n,m; cin>>n>>m;
	cout<<qpow(qpow(2,m)-1,n);
	
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
//	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

