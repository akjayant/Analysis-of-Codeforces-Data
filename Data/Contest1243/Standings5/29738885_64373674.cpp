//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math") 
//#pragma GCC target("avx2")
#define _CRT_SECURE_NO_WARNINGS // - for VisualStudio: do not disturb about warnings
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <climits>

using namespace std;
#define open_streams ifstream fin("strange.in");ofstream fout("strange.out")
#define close_streams fin.close();fout.close()
#define speed cout.tie(0);cin.tie(0);ios_base::sync_with_stdio(0)
#define pus system("pause");
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define UNIQ(a) a.resize(unique(all(a)) - a.begin())
#define eps 1e-6
#define bpopcnt __builtin_popcountll // ll for long long
//const double PI = M_PI;
const int INF = INT_MAX;
const ll limit = 1LL * 1e18;
const int MOD = 1e9 + 711;
const int MOD2 = 1e9 + 933;
const int MOD3 = 1e9 + 993;
//---------------------------------------------------------------------------
const int mod = 1e9 + 7;
const int maxn = 5e5 + 100;




signed main() {
	speed;
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		a[0] = INF;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		sort(rall(a));
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] >= i) {
				++ans;
			}
			else {
				break;
			}
		}
		cout << ans << '\n';
	}
	cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}