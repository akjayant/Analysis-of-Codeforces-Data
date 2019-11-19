#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define zoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll solve() {
	ll n, m, i;
	cin >> n;
	vector<ll> DLS(2, 0), JLS(2, 0);
	for(i = 0; i < n; i += 1) {
		ll temp;
		cin >> temp;
		DLS[temp % 2] += 1;
	}
	cin >> m;
	for(i = 0; i < m; i += 1) {
		ll temp;
		cin >> temp;
		JLS[temp % 2] += 1;
	}
	ll ans = DLS[0] * JLS[0] + DLS[1] * JLS[1];
	return ans;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    zoom;
    ll t;
    cin >> t;
    while(t--)
    	cout << solve() << endl;
    return 0;
}