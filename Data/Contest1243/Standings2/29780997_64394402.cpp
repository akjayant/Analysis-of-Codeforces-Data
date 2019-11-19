#include <bits/stdc++.h>

#define N 100010 

using namespace std;

typedef long long ll;

ll a[N];
int main() {
	ll n;
	cin >> n ;
	ll tmp = n;
	for (int i = 2; (ll)i * i <= tmp; i ++ ) {
		if (tmp % i == 0) {
			a[ ++ a[0]] = i;
			while (tmp % i == 0) {
				tmp /= i;
			}
		}
	}
	if (tmp != 1) {
		a[ ++ a[0]] = tmp;
	}
	if (a[0] == 1) {
		cout << a[1] << endl ;
	}
	else {
		puts("1");
	}
	return 0;
}