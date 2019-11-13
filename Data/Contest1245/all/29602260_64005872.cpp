#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = a; i >= b; i--)
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef double db;
const db EPS = 1e-9;
const int N = 1e3+10;
using namespace std;

void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}

int n,a[5],ans[N];
char s[N];
map<char,int> mp;

int main()
{
	mp['R'] = 2; mp['P'] = 3; mp['S'] = 1;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		scanf("%s",s+1);
		int win = 0;
		rep(i,1,n){
			int pos = mp[s[i]];
			if(a[pos] >= 1){
				ans[i] = pos;
				a[pos]--;
				win++;
			}
			else ans[i] = 0;
		}
		if(win*2 >= n){
			printf("YES\n");
			rep(i,1,n){
				if(ans[i] != 0){
					if(ans[i] == 1) printf("R");
					else if(ans[i] == 2) printf("P");
					else printf("S");
				}
				else{
					if(a[1] > 0) {printf("R"); a[1]--;}
					else if(a[2] > 0) {printf("P"); a[2]--;}
					else {printf("S"); a[3]--;}
				}
			}
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}