#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 20101009;
const int maxn = 1e6 + 10;
ll num[maxn];
int main() {
	ll n;
	scanf("%lld", &n);
	int len = 0;
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			num[++len] = i;
			if (n != i * i)
				num[++len] = n / i;
		}
	}
	if (len == 0)
		printf("%lld\n", n);
	else {
		int f = 1;
		sort(num + 1, num + 1 + len);
		for (int i = 2; i <= len && f; i++)
			if (num[i] != num[i - 1] * num[1])
				f = 0;
		if (f)
			printf("%lld\n", num[1]);
		else
			printf("1\n");
	}
}