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
const int P = 998244353;

inline void solve(){
	int a,b; scanf("%d%d",&a,&b);
	puts(__gcd(a,b)!=1?"Infinite":"Finite");
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

