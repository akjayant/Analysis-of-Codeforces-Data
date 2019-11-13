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

int main() {
	fast;
	int t;
	cin >> t;

	while(t--) {
		int a, b;
		cin >> a >> b;
		if(__gcd(a,b) > 1) cout << "Infinite\n";
		else cout << "Finite\n";
	}
}