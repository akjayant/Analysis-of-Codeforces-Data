#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof((a)))

using namespace std;

typedef long long ll;
typedef double db;

const int MN = 3e5 + 5;
const int P = 998244353;

int a,c[MN];

inline void solve(){
	int n; scanf("%d",&n);
	for__(i,1,1000) c[i]=0;
	for_(i,0,n){
		scanf("%d",&a);
		for__(i,1,a)
			++c[i];
	}
	rof__(i,1000,1)
		if(c[i]>=i)
			return printf("%d\n",i), void();
	
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

