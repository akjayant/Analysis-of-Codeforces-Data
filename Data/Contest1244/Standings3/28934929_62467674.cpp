#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <stack>
#include <memory.h>
#include <list>
#include <numeric>
#include <functional>
#include <complex>
#include <cassert>
#include <regex>
#include <random>

#define ll long long
#define ld long double
#define ull unsigned ll
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pii pair<int,int> 
#define pll pair<ll, ll> 
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vector<int>>
#define forn(it,from,to) for(ll (it)=from; (it)<to; (it)++)
ld pi = acos(-1.0);
using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("hotel.in", "r", stdin);
	//freopen("hotel.out", "w", stdout);
	//reopen("input.txt", "r", stdin);
	//reopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		ll mn = 1e9;
		forn(i, 0, n) {
			if (s[i] == '1') {
				mn = i;
				break;
			}
		}
		reverse(all(s));
		forn(i, 0, n) {
			if (s[i] == '1') {
				mn = min(i, mn);
				break;
			}
		}
		ll ans = n;
		if (mn != 1e9) {
			ans = max(ans, n * 2 - mn * 2);
		}
		cout << ans << '\n';
	}
	return 0;
}