#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <tuple>
#include <vector>
#include <bitset>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;

int main() {
	ll n;
	scanf("%I64d", &n);
	std::vector<ll> divs;
	ll x = n;
	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			divs.push_back(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		divs.push_back(x);
	}
	if (divs.size() == 1) {
		printf("%I64d", divs.front());
	} else {
		printf("1");
	}
	return 0;
}