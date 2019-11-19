#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define foe(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define long long long 
#define db double 
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9+7;
const long MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

const int N = 1e5+1;
int n, m;
long F[2][N], res;

int main()
{
	fastio;
	cin >> n >> m;
	F[0][0] = 1; F[1][0] = 1;
	F[1][1] = 1; F[0][1] = 1;
	for (int i = 2; i <= max(n,m); i++){
		F[0][i] = (F[1][i-1] + F[1][i-2]) % MOD;
		F[1][i] = (F[0][i-1] + F[0][i-2]) % MOD;
	}
	res = F[0][n] + F[1][n] + F[0][m] + F[1][m] - 2;
	res %= MOD;
	(res += MOD) %= MOD;
	cout << res;
	return 0;
}