#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = a; i >= b; i--)
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef double db;
const db EPS = 1e-9;
const int N = 1e5+100;
const ll mod = 1e9+7;
using namespace std;

void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}

char s[N];
ll f[N][2];

int main()
{
	scanf("%s",s+1);
	int len = strlen(s+1);
	rep(i,1,len)
		if(s[i] == 'w' || s[i] == 'm'){
			printf("0\n");
			return 0;
		}
	f[0][0] = 1;
	rep(i,1,len){
		f[i][0] = (f[i-1][0]+f[i-1][1])%mod;
		if(s[i] == s[i-1]){
			if(s[i] == 'u' || s[i] == 'n') f[i][1] = f[i-1][0];
		}
	}
	ll ans = f[len][0]+f[len][1];
	ans %= mod;
	printf("%lld\n",ans);
	return 0;
}