#include <cstdio>
#include <algorithm>
#include <utility>

#define FOR(i, n) for(int i = 0; i < n; i++) 

#define pow CHANGETHENAMESTUPID

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

void load() {

}

bool solve() {
		int a, b; scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		if (a == 1) return true;
		if (__gcd(a, b) > 1) return false;
		return true;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		load();
		printf("%s\n", solve() ? "Finite" : "Infinite");
	}
	return 0;
}
