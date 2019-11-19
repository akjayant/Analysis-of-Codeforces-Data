#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset((a), v, sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 100005;

int n;
int dat[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dat[i];
	}

	sort(dat, dat+n);

	ll sumX = 0, sumY = 0;
	for (int i = 0; i < n/2; i++) {
		sumX += dat[i];
	}
	for (int i = n/2; i < n; i++) {
		sumY += dat[i];
	}

	ll ans = sumX*sumX + sumY*sumY;
	cout << ans << "\n";
	return 0;
}