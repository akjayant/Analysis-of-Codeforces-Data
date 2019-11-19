#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const ll MOD = (ll)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<ll> v; // 공장 번호
vector<pll> ans;

pii vec[2000];
ll c[2000];
ll k[2000];
ll mii[2000];
pll ab[2000];
char visit[2000];

int dist(int x, int y) {
	return abs(vec[x].first - vec[y].first) + abs(vec[x].second - vec[y].second);
}

int main() {
	memset(mii, 0x3f, sizeof(mii));
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &vec[i].first, &vec[i].second);

	pll miv = { (ll)2e9, (ll)1e9 };
	for (int i = 0; i < n; i++) {
		scanf("%lld", &c[i]);
		miv = min(miv, pll(c[i], i));
	}
	for (int i = 0; i < n; i++) scanf("%lld", &k[i]);

	v.push_back(miv.second);
	ll ret = 0;
	ret += miv.first;
	visit[miv.second] = 1;

	ll pre = miv.second;
	for (int cnt = 1; cnt < n; cnt++) {
		miv = { (ll)2e9, (ll)2e9 };
		
		ll mm = (ll)1e18;
		ll a, b;
		for (int i = 0; i < n; i++) {
			if (visit[i]) continue;
			if (mii[i] > (k[i] + k[pre]) * dist(i, pre)) {
				mii[i] = (k[i] + k[pre]) * dist(i, pre);
				ab[i] = { i, pre };
			}
			if (mm > mii[i]) {
				mm = mii[i];
				a = ab[i].first, b = ab[i].second;
			}
			miv = min(miv, pll(c[i], i));
		}

		if (miv.first < mm) {
			visit[miv.second]++;
			v.push_back(miv.second);
			ret += miv.first;
			pre = miv.second;
		}
		else {
			int tt = a;
			if (visit[a]) tt = b;
			visit[tt]++;
			ans.push_back({ a, b });
			ret += mii[tt];
			pre = tt;
		}
	}

	printf("%lld\n", ret);
	printf("%d\n", sz(v));
	for (ll i : v)
		printf("%lld ", i + 1);
	printf("\n");
	printf("%d\n", sz(ans));
	for (pll i : ans)
		printf("%lld %lld\n", i.first + 1, i.second + 1);
}