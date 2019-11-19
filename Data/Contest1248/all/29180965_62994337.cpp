#include <stdio.h>
#include <vector>
#include <algorithm>
#define i(a) scanf("%lld",&a)
#define rep(a,b,c) for(long long a=b;a<c;a++)
typedef long long ll;
using namespace std;
ll a[501];
ll n;
bool check = true;
vector<long long> v;
ll foo() {
	ll sum = 0;
	ll m = n;
	rep(i, 0, n) {
		sum += a[i];
		if (m > sum) {
			m = sum;
			v.clear();
			v.push_back(i);
		}
		else if (m == sum) {
			v.push_back(i);
		}
	}
	if (sum != 0) check = false;
	return v.size();
}
int main() {

	i(n);
	getchar();
	ll sum = 0;
	ll min = n;
	rep(i, 0, n) {
		char c = getchar();
		if (c == '(') a[i] = 1;
		else a[i] = -1;
	}
	ll ma = 0;
	ll ki, kj;
	ma = foo();
	if (!check) {
		printf("0\n1 1");
		return 0;
	}
	ki = 1; kj = 1;
	rep(i, 0, n) {
		rep(j, i + 1, n) {
			ll temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			ll tt = foo();
			if (ma < tt) {
				ma = tt;
				ki = i; kj = j;
			}
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	ll temp = a[ki];
	a[ki] = a[kj];
	a[kj] = temp;
	foo();
	printf("%lld\n", ma);
	printf("%lld %lld", ki+1, kj+1);

}