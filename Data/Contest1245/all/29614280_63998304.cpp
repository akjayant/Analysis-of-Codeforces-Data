#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cassert>
using namespace std;

typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
constexpr int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		while (a) {
			b %= a;
			swap(a, b);
		}
		if (b == 1) {
			cout << "Finite\n";
		}
		else {
			cout << "Infinite\n";
		}
	}
	return 0;
}