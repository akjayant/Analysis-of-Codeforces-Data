#include <stdio.h>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define i(x) scanf("%d",&x)
#define l(x) scanf("%lld",&x)
#define rep(a,b,c) for(int a = b;a<c;a++)
#define p pair<long long,long long>
using namespace std;
typedef long long ll;

int main() {
	int t; i(t);
	while (t--) {
		int n; i(n);
		vector<int> v(n);
		rep(i, 0, n)i(v[i]);
		sort(v.begin(), v.end());
		int ans = 0;
		while (ans < n&&v[n - 1 - ans] >= ans + 1) {
			ans++;
		}
		printf("%d\n", ans);
	}
}