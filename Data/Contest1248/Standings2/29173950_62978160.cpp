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
const int MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

int T, n, m;
long cnt[2][2], res;

int main()
{
	fastio;
	cin >> T;
	while (T--){
		cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			cnt[0][x % 2]++;
		}
		cin >> m;
		for (int i = 1; i <= m; i++){
			int x; cin >> x;
			cnt[1][x % 2]++;
		}
		res = cnt[0][0] * cnt[1][0] + cnt[0][1] * cnt[1][1];
		cout << res << '\n';
	}
	return 0;
}