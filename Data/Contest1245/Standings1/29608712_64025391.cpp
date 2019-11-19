#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 1e9+7;

int a[10][10];
double dp[111];

int f(int x, int y) {
	if(x % 2 == 0) return 10 * x + y;
	else return 10*x + (9 - y);
}

pii g(int k) {
	if(k / 10 % 2 == 0) return {k/10, k%10};
	else return {k/10, 9 - k%10};
}

int main() {
	fast;
	pre(10);

	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			cin >> a[i][j];
		}
	}

	dp[0] = 0;
	dp[1] = 6;
	dp[2] = 6;
	dp[3] = 6;
	dp[4] = 6;
	dp[5] = 6;

	for(int i=6; i<100; i++) {
		for(int j=1; j<=6; j++) {
			pii x = g(i - j);
			x.fi -= a[x.fi][x.se];
			dp[i] += 1.0/6.0 * min(dp[i-j], dp[f(x.fi, x.se)]);
		}
		dp[i]++;
	}

	cout << dp[99];
}