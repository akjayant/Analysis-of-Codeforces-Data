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

char s[MN], t[MN];
int cnt[260];

inline void solve(){
	int n; scanf("%d",&n);
	scanf("%s%s",s,t);
	for__(i,'a','z') cnt[i]=0;
	for_(i,0,n) ++cnt[s[i]], ++cnt[t[i]];
	for__(i,'a','z') if(cnt[i]&1) return puts("NO"), void();
	puts("YES");
	vector<pair<int,int>>v;
	for_(i,0,n){
		if(s[i]!=t[i]){
			bool ok=0;
			for_(j,i+1,n)
				if(ok) break;
				else if(s[i]==s[j])
					swap(s[j],t[i]),
					v.emplace_back(j,i),
					ok=1;
			for_(j,i+1,n)
				if(ok) break;
				else if(s[i]==t[j])
					swap(s[j],t[j]),
					v.emplace_back(j,j),
					swap(s[j],t[i]),
					v.emplace_back(j,i),
					ok=1;
		}
	}
	printf("%u\n",v.size());
	for(auto [a,b]:v) printf("%d %d\n",a+1,b+1);
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

