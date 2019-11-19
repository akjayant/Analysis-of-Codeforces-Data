#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <iostream>
#include <string>
#include <ctime>
#define ll long long
#define pint pair<int,int>
#define pii pair<int,int>
#define pci pair<char,int>
#define pdd pair<double,double>
#define pli pair<int,int>
#define pil pair<int,int>
#define pdi pair<double,int>
#define pdd pair<double,double>
#define mod 1000000007
#define mod1 1000000009
#define mod2 1000000021
#define INF 1987654321
#define MAX 2000001
long double PI = 3.141592653589793238462643383279502884197;
using namespace std;

/* 🐣🐥 */
int num[2];
int main() {
	int n, t, x;
	ll ans;
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		num[0] = num[1] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			num[x%2]++;
		}
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			ans += num[x % 2];
		}
		printf("%lld\n", ans);
	}

	return 0;
}