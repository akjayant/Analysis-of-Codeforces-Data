#include <stdio.h>
#include <vector>
#include <algorithm>
#define i(a) scanf("%lld",&a)
using namespace std;

int main() {
	long long t;
	i(t);
	while (t--) {
		long long n, m;
		long long a = 0, b = 0, c = 0, d = 0;
		i(n);
		while (n--) {
			long long x;
			i(x);
			if (x % 2 == 0)a++;
			else b++;
		}
		i(m);
		while (m--) {
			long long x;
			i(x);
			if (x % 2 == 0)c++;
			else d++;
		}
		printf("%lld\n", a * c + b * d);
	}
}