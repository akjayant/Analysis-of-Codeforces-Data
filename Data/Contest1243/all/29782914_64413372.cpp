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
#include <stack>
#include <memory.h>
#include <list>
#include <numeric>
#include <functional>
#include <complex>
#include <cassert>
#include <regex>
#include <random>
#include <fstream>

#define ll long long
#define ld long double
#define ull unsigned ll
#define mp(xx, yy) make_pair(xx, yy)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pii pair<int,int> 
#define pll pair<ll, ll> 
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vector<int>>
#define forn(it,from,to) for(int (it)=from; (it)<to; (it)++)
//#define endl '\n'
ld pi = acos(-1.0);
const int mod = 1e9 + 7;
using namespace std;


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("kgraph.in", "r", stdin);
	//freopen("kgraph.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(20); cout.setf(ios::fixed);
	int k;
	cin >> k;
	forn(ha, 0, k) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		vector<pii> ans;
		forn(i, 0, n) {
			if (a[i] != b[i]) {
				int k = 1;
				forn(j, i + 1, n) {
					if (a[j] == a[i]) {
						k = 0;
						ans.push_back({ j + 1,i + 1 });
						a[j] = b[i];
						b[i] = a[i];
						break;
					}
				}
				if (k) {
					forn(j, i + 1, n) {
						if (b[j] == a[i]) {
							ans.push_back({ j + 1,j + 1 });
							ans.push_back({ j + 1,i + 1 });
							b[j] = a[j];
							a[j] = b[i];
							b[i] = a[i];
							break;
						}
					}
				}
			}
		}
		if (ans.size() > 2 * n||a!=b) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
			cout << ans.size() << endl;
			forn(i, 0, ans.size())
				cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
	return 0;
}