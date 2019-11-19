#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }

template <typename T> inline T read(){
    T sum = 0;
    int fl = 1,ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') fl = -1;
    for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
    return sum * fl;
}

const int mod = 1e9 + 7;
const int maxn = 100000 + 5;

int n,m;
int dp[maxn];

inline void Solve (){
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= max(n,m); i++){
		dp[i] = dp[i - 1] + dp[i - 2] % mod;
	}
	printf("%lld\n",(2 * (dp[n] + dp[m] - 1)) % mod);
}

inline void Input (){
	n = read<int>();
	m = read<int>();
}

signed main(){
	Input();
	Solve();
	return 0;
}

