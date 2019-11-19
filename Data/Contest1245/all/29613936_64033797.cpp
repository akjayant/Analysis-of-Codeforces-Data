#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")

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

const int maxn = 1000 + 5;
const int mod = 1e9 + 7;

int cnt;
int a[maxn][maxn],id[maxn];
double dp[maxn];

inline void init(){
	for(int i = 1; i <= 10; i++){
		if(i % 2){
			for(int j = 1; j <= 10; j++){
				cnt++;
				a[i][j] = cnt;
			}
		}else{
			for(int j = 10; j >= 1; j--){
				cnt++;
				a[i][j] = cnt;
			}
		}
	}
}

inline void Solve(){
	for(int i = 2; i <= 10; i++){
		dp[a[10][i]] = 1;
		for(int j = 1; j <= min(i - 1,6); j++){
			dp[a[10][i]] += dp[a[10][i - j]] / 6;
		}
		if(i <= 6) dp[a[10][i]] = dp[a[10][i]] * 6 / (i - 1);
	}
	for(int i = 90; i >= 1; i--){
		dp[i] = 1;
		for(int j = 1; j <= 6; j++){
			dp[i] += min(dp[i + j],dp[id[i + j]]) / 6;
		}
	}
	printf("%.8lf\n",dp[1]);
}

inline void Input(){
	init();
	for(int i = 10; i >= 1; i--){
		for(int j = 1; j <= 10; j++){
			int x = read<int>();
			id[a[i][j]] = a[i + x][j];
		}
	}
}

int main(){
	Input();
	Solve();
	return 0;
}
