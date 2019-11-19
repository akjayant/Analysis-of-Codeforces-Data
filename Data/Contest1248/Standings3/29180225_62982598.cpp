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
int t, n, m, p, cnt[2];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while(t--) {
		vector<pii> v;
		cin >> n;
		rep(i, 0, n) cin >> p, cnt[p&1]++;
		cin >> m;
		ll ans=0;
		rep(i, 0, m) cin >> p, ans += cnt[p&1];
		cout << ans << endl;
		cnt[0]=cnt[1]=0;
	}
}
