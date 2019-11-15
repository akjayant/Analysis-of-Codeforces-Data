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

const int MN = 3e3 + 5;
const int P = 998244353;

int t[MN][MN];

inline void solve(){
	int n; scanf("%d",&n);
	int cnt=0;
	for__(j,1,n)
		if(j&1) 
			for__(i,1,n)
				t[i][j]=++cnt;
		else
			rof__(i,n,1)
				t[i][j]=++cnt;
	for__(i,1,n)
		for__(j,1,n)
			printf("%d%c",t[i][j]," \n"[j==n]); 
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
//	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

