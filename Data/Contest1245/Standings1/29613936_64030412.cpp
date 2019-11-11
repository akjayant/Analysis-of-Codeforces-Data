#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }

template <typename T> inline T read(){
    T sum = 0;
    int fl = 1,ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') fl = -1;
    for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
    return sum * fl;
}

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int n,cnt1,cnt2,ans = 1;
int dp[maxn];
char s[maxn];

void init(){
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
}

inline void Solve(){
	n = strlen(s + 1);
	init();
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'm' || s[i] == 'w'){
			printf("0\n");
			return;
		}
		if(s[i] != 'u' && cnt1){
			ans = 1ll * ans * dp[cnt1] % mod;
			cnt1 = 0;
		}
		if(s[i] != 'n' && cnt2){
			ans = 1ll * ans * dp[cnt2] % mod;
			cnt2 = 0;
		}
		if(s[i] == 'u') cnt1++;
		if(s[i] == 'n') cnt2++;
	}
	if(cnt1){
		ans = 1ll * ans * dp[cnt1] % mod;
		cnt1 = 0;
	}
	if(cnt2){
		ans = 1ll * ans * dp[cnt2] % mod;
		cnt2 = 0;
	}
	printf("%d\n", ans);
}

inline void Input(){
	scanf("%s",s + 1);
}

int main(){
	Input();
	Solve();
	return 0;
}
