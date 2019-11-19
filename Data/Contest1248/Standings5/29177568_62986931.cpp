#include <bits/stdc++.h>

#pragma GCC optimize("03")

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define pow2(x) ((x) * (x))
#define rev reverse
#define in insert
#define sz(x) (int)x.size()

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, pii> piii;

const ll inf = (ll)1e18;
const int MAXN = (int)1e5;
const ll mod = (ll)1e9 + 7;

const double pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 100500;

int main() {
	int t;
	scanf("%i", &t);

	for(int i = 0; i < t; i++) {
		ll n;
		scanf("%I64d", &n);

		ll cnt_odd = 0, cnt_even = 0;

		vector<ll> p(n);
		for(int j = 0; j < n; j++) {
			scanf("%I64d", &p[ j ]);

			if(p[ j ] % 2) cnt_odd ++;
			else cnt_even++;
		}

		ll m;
		scanf("%I64d", &m);

		ll cnt_odd2 = 0, cnt_even2 = 0;

		vector<ll> q(m);
		for(int j = 0; j < m; j++) {
			scanf("%I64d", &q[ j ]);

			if(q[ j ] % 2) cnt_odd2 ++;
			else cnt_even2 ++;
		}

		//printf("%i, %i, %i, %i\n", cnt_odd, cnt_odd2, cnt_even, cnt_even2);
		//int fi = max(cnt_odd2, cnt_odd), se = max(cnt_even, cnt_even2);

		printf("%I64d\n", cnt_odd2 * (ll)cnt_odd + cnt_even * (ll)cnt_even2);
	}
}