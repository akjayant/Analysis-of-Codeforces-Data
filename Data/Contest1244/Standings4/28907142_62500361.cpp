#pragma GCC optimize("03")
#include <bits/stdc++.h>
#define ll long long 
#define fi first
#define se second

//CHECK FOR N = 1 OR OTHER DUMB TESTS 

using namespace std;

int n;
ll k;
ll a[100100], dp[100100], calc[100100];

ll getval(ll v) {
	int st = 1;
	int dr = n;
	int mid;
	while (st <= dr) {
		mid = (st + dr) / 2;
		if (a[mid] >= v)
			dr = mid - 1;
		else st = mid + 1;
	}
	
	int id = st;
	ll val = dp[id];
	ll cnt = (n - id + 1);
	val -= cnt * v;
	return val;
}

ll getvall(ll v) {
	int st = 1;
	int dr = n;
	int mid;
	while (st <= dr) {
		mid = (st + dr) / 2;
		if (a[mid] <= v)
			st = mid + 1;
		else dr = mid - 1;
	}
	
	int id = dr;
	ll val = calc[id];
	val += 1ll * id * abs(v - a[id]);
	
	return val;
}

ll get(ll left, ll right) {
	ll val = getval(right);
	val += getvall(left);
		
	return val;
}

int main() {
	//ifstream cin("tst.in");
	//ofstream out("tst.out");
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a + 1, a + n + 1);	
		
	for (int i = n; i > 0; i--)
		dp[i] = a[i] + dp[i + 1];
		
	ll v = 0;
	ll f = a[1];	
	for (int i = 1; i <= n; i++) {
		ll dif = a[i] - f;
		v += (1ll * i - 1) * dif;
		calc[i] = v;
		f = a[i];
	}
	
	ll median = (a[1] + a[n]) / 2ll;
	ll dist = 0;
	for (int i = 1; i <= n; i++)
		dist += abs(median - a[i]);
		
	if (dist <= k)
		return cout << 0, 0;
		
	ll st = 0;
	ll dr = a[n] - a[1];
	ll mid;
	
	while (st <= dr) {
		mid = (st + dr) / 2ll;
		
		ll l = 1, r = a[n], mij;
		while (l <= r) {
			mij = (l + r) / 2;
//			cerr << l << ' ' << r << ' ' << mij << '\n';
			if (get(mij, mij + mid) >= get(mij + 1, mij + mid + 1))
				l = mij + 1;
			else r = mij - 1;
		}
		
//		cout << mid << "   " << r << ' ' << r + mid - 1 << ' ' << get(r, r + mid) << '\n';
		r++;
		if (get(r, r + mid) <= k) 
			dr = mid - 1;
		else st = mid + 1;
		
//		int a;
//		cin >> a;
	}
	
	cout << st;
	return 0;
}