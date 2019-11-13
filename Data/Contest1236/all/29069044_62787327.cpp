#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false)
#define popcnt __builtin_popcount
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb emplace_back
#define pii pair<int,int>
#define all(n) (n).begin(),(n).end()
#define rep(i,a,n) for (int i = a; i <= n; i++)
#define QAQ sort(co+1,co+1+n)
const int maxn = 3e5 + 5;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

ll co[maxn];


string str;
ll n, m, k, t, need;

vector<int>ff[maxn];
int dp[maxn][2];
int main() {
	IO;
	ll a, b, c;
	cin >> t;
	while(t--){
		int ans = 0;
	cin >> a >> b >> c;
	while(b && c){
		if(b < 1 || c < 2)	break;
		c -= 2;
		b -= 1;
		ans += 3;
	}
	while(a && b){
		if(a < 1 || b < 2)	break;
		a -= 1;
		b -= 2;
		ans += 3;
	}
	cout << ans << endl;
	}
	
	
}

