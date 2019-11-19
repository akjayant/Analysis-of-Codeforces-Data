#include <stdio.h>
#include <stack>
#include <map>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#include <climits>
#include <unordered_map>
#include <iterator> 
#include <bitset>
#include <complex>
#include <random>
#include <chrono>
#include <functional>
using namespace std;
typedef complex<double> cd;
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define mp make_pair
#define inf32 INT_MAX
#define inf64 LLONG_MAX
#define PI acos(-1)
#define cos45 cos(PI/4)
#define ld long double
#define inf INT_MAX
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pil pair<int, ll>
#pragma GCC optimize("O3")
//#define x first
//#define y second
const int mods[10] = { 1000000007, 999999937, 999999929, 999999893, 999999883, 999999797, 999999761, 999999757, 999999751, 999999739 };
const int mod = 1000000007;
int rand_mods[2];
const long double eps = 1e-10;
const int siz = 1e5 + 5, siz2 = (1 << 20) + 5, lg = 21, block = 448, block2 = 1000, mxv = 5e5, sqrt_mod = 31630;
const int alpha_sz = 26;

int t, n;
char arr[1005];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, arr);
		int mx = INT_MIN;
		for (int i = 0; i < n; i++) {
			if (arr[i] == '1') {
				mx = max(mx, max(i+1, n-i));
			}
		}
		if (mx == INT_MIN) {
			printf("%d\n", n);
		}
		else {
			printf("%d\n", max(mx*2, n));
		}
 	}
	return 0;
}