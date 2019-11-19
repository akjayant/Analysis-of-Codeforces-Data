#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;

typedef long long ll;
ll n, k, l, r, a[N], b[N];

void f() {
	for (l; l < r; l++) {
		if (a[l] == a[l + 1]) b[l + 1] += b[l];
		else return;
	}
}

void g() {
	for (r; r > l; r--) {
		if (a[r] == a[r - 1]) b[r - 1] += b[r];
		else return;
	}
}

int main()
{
	ll i, t;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
		b[i] = 1;
	}
	sort(a, a + n);
	l = 0, r = n - 1;
	f();
	g();
	for (; l < r;) {
        if (b[l] < b[r]) {
			t = (a[l + 1] - a[l]) * b[l];
			if (t <= k) {
				k -= t;
				a[l] = a[l + 1];
				f();
			} else {
				a[l] += k / b[l];
				break;
			}
        } else {
			t = (a[r] - a[r - 1]) * b[r];
			if (t <= k) {
				k -= t;
				a[r] = a[r - 1];
				g();
			} else {
				a[r] -= k / b[r];
				break;
			}
        }
	}
    cout << a[r] - a[l] << endl;
    return 0;
}