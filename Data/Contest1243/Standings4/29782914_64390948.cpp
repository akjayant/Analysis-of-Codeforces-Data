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
	ll n;
	cin >> n;
	vll v;
	for (ll i = 2; i*i <= n; ++i) {
		if (n%i == 0) {
			v.push_back(i);
			while (n%i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1)
		v.push_back(n);
	if (v.size() == 1) {
		cout << v[0];
	}
	else cout << 1;
	return 0;
}