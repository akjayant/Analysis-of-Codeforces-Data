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

char s[MN],ans[MN];
string he="RPS";
string me="PSR";
int cnt[260];

inline void solve(){
	int n; scanf("%d",&n);
	int a,b,c; scanf("%d%d%d",cnt+'R',cnt+'P',cnt+'S');
	//aR bP cS
//	cnt['R']=a, cnt['P']=b, cnt['S']=c;
//	for_(i,0,3) cnt[t[i]]=0;
	scanf("%s",s);
	for__(i,0,n) ans[i]=0;
//	for_(i,0,n) ++cnt[s[i]];
	int win=0;
	for_(i,0,n){
		int ok=0;
		for_(j,0,3)
			if(s[i]==he[j] && cnt[me[j]]>0)
				--cnt[me[j]], ans[i]=me[j], ok=1;
		if(ok) ++win;
//		else for_(j,0,3) if(cnt[me[j]]>0){
//			ans[i]=me[j], --cnt[me[j]];
//			break;
//		}
	}
	for_(i,0,n) if(!ans[i])	//����Ӯ�Ĳ�������
		for_(j,0,3) if(cnt[me[j]]>0){
			ans[i]=me[j], --cnt[me[j]];
			break;
		}
//for_(j,0,3) printf("%d ",cnt[me[j]]);
//cout<<win<<' ';
	if(win>=(n+1)/2){
		puts("YES");
		puts(ans);
	}else puts("NO");
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

