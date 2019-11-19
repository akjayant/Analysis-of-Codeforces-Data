// youngjinp20
// 2019 10

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

int main() {
	int n;
	ll a[100000];
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	ll s1 = 0;
	ll s2 = 0;
	for (int i=0; i<n/2; i++) {
		s1 += a[i];
	}
	for (int i=n/2; i<n; i++) {
		s2 += a[i];
	}

	printf("%lld\n", s1*s1+s2*s2);
	return 0;
}
