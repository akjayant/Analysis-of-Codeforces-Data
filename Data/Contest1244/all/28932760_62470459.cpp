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

char s[MN];

inline void solve(){
	int n; scanf("%d%s",&n,s+1);
	int ans=n;
	int cnt=0;
	for__(i,1,n) if(s[i]=='1') ans=max(ans,i<<1),++cnt;
	rof__(i,n,1) if(s[i]=='1') ans=max(ans,n-i+1<<1);
//	for__(i,1,n) if(s[i]=='1') ++cnt;
	ans=max(ans,n+cnt);
	printf("%d\n",ans);
	
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}