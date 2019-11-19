#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef long long LL;
LL n, g;

LL gcd(LL a, LL b) {
	return b == 0? a: gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);

	while(cin >> n) {
		g = n;
		for(LL i = 2; i * i <= n; ++i) {
			if(n % i == 0) {
				g = gcd(g, i);
				g = gcd(g, n / i);
			}
		}
		cout << g << endl;
	}

    return 0;
}