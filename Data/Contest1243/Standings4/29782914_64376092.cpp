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
	int t;
	cin >> t;
	forn(i, 0, t) {
		int n;
		cin >> n;
		vi v(n);
		forn(j, 0, n) {
			cin >> v[j];
		}
		for (int j = 10000; j > 0; --j) {
			int x = 0;
			forn(k, 0, n)
				if (v[k] >= j)
					x++;
			if (x >= j) {
				cout << j<<endl;
				break;
			}
		}
	}
	return 0;
}