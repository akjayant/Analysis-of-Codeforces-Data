#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long

const int N = 1e5+11;
int n;
ll k;
int a[N];
vector <pair <int, int> > b, c;
ll raz;

int main() {
	cin >> n >> k;
	for (int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	sort (a, a+n);
	raz = a[n-1]-a[0];
	int br = 1;
	for (int i=0;i<n-1;i++) {
		if (a[i] != a[i+1]) {
			b.pb(mp(br, a[i+1]-a[i]));
		}
		br++;
	}
	br = 1;
	for (int i=n-1;i>0;i--) {
		if (a[i] != a[i-1]) {
			c.pb(mp(br, a[i]-a[i-1]));
		}
		br++;
	}
	b.pb(mp(1e6, 0));
	c.pb(mp(1e6, 0));
	int x = 0, y = 0;
	while (k >= min(b[x].ff, c[y].ff) && raz > 0) {
		if (b[x].ff < c[y].ff) {
			ll sada = b[x].ss;
			sada *= b[x].ff;
			sada = min(sada, k);
			sada -= (sada % b[x].ff);
			raz -= sada/b[x].ff;
			k -= sada;
			x++;
		}
		else {
			ll sada = c[y].ff;
			sada *= c[y].ss;
			sada = min(sada, k);
			sada -= (sada % c[y].ff);
			raz -= sada/c[y].ff;
			k-=sada;
			y++;
		}
	}
	if (raz < 0) raz = 0;
	cout << raz;
	return 0;
}