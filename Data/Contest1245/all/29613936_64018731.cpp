#include <bits/stdc++.h>
#define int long long
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

const int maxn = 40;

int T;
int dp[maxn + 5][2][2];

int calc(int x,int y){
	if(x < 0 || y < 0) return 0;
	memset(dp,0,sizeof(dp));
	dp[maxn][0][0] = 1;
	for(int i = maxn - 1; i >= 0; i--){
		for(int j = 0; j <= 1; j++){
			for(int k = 0; k <= 1; k++){
				int nx = j || (x & (1ll << i));
				int ny = k || (y & (1ll << i));
				dp[i][nx][ny] += dp[i + 1][j][k];
				if((x & (1ll << i)) || j) dp[i][j][ny] += dp[i + 1][j][k];
				if((y & (1ll << i)) || k) dp[i][nx][k] += dp[i + 1][j][k];
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			ans += dp[0][i][j];
		}
	}
	return ans;
}

inline void Solve(){
	while(T--){
		int x,y;
		x = read<int>();
		y = read<int>();
		printf("%lld\n",calc(y,y) + calc(x - 1,x - 1) - calc(x - 1,y) * 2);
	}
}

inline void Input(){
	T = read<int>();
}

signed main(){
	Input();
	Solve();
	return 0;
}
