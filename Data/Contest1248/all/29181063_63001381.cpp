#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define m_p make_pair
#define p_i pair<int, int> 
#define maxn 100005
#define maxm 505
#define _for(i, a) for(LL i = 0; i < (a); i++)
#define _rep(i, a, b) for(LL i = (a); i <= (b); i++)
#define outval(a) cout<<#a<<": "<<a<<"\n"
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const LL MAXN = 110;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
typedef vector< double > vec;
typedef vector< vec > mat;

const double eps = 1e-8;

LL dp[maxn];	//0:do	1:not do


void init() {
	dp[0] = 2, dp[1] = 4;
}



int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);

	int n, m;
	cin >> n >> m;
	init();
	if (n < m) swap(n, m);
	_rep(i, 2, n - 1) {
		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= mod;
	}
	cout << (dp[n - 1] - 2 + dp[m - 1]) % mod << "\n";
	return 0;
}

/*

*/
