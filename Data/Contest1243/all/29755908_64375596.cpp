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
const int maxn = 1000 + 100;
int T, n, ans;
int num[maxn];

int main() {
	ios::sync_with_stdio(false);

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &num[i]);
		}
		sort(num + 1, num + n + 1);
		for(int i = 1; i <= n; ++i) {
			if(num[n - i + 1] >= i) {
				ans = i;
			}
		}
		printf("%d\n", ans);
	}

    return 0;
}