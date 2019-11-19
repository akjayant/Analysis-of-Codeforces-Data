#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll ((ll) 1e18 + 10)

#define endl '\n'
#define fi first
#define se second
#define pb emplace_back
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a)-1; i >= (b); i--)

const int N = 100010;
ll dp[N];
int n, m;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	rep(j, 0, 2) dp[0] = dp[1] = 1;
	rep(i, 2, max(n,m)+1) rep(j, 0, 2) dp[i] = (dp[i-1] + dp[i-2])%mod;
	cout << (2*dp[m]%mod + (2*dp[n]-2+mod)%mod)%mod << endl;
}
