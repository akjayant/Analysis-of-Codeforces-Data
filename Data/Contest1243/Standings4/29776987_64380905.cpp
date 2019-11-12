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

inline void solve(){
	int n; scanf("%d",&n);
	scanf("%s%s",s,t);
	int fst=-1, scd=-1, ok=1;
	for_(i,0,n){
		if(s[i]!=t[i]){
			if(fst==-1) fst=i;
			else if(scd==-1) scd=i;
			else ok=0;
		}
	}
	if(!ok || scd==-1) puts("NO");
	else if(ok && scd!=-1 && s[fst]==s[scd] && t[fst]==t[scd]) puts("YES");
	else if(fst==-1) puts("YES");
	else puts("NO");
	
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

