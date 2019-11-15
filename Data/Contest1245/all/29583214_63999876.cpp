//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <random>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

using ll = long long;
using ld = long double;
using itn = int;
using dd = double;
mt19937 gen(41);
const ld eps = 1e-7;
const ll INF = 1e17;
const dd pi = acos(dd(-1));

#define endl '\n'

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

/** SOLVE

SOLVE

**/

int main() {
#ifdef _DEBUG
	auto input = freopen("input.txt", "r", stdin);
	auto output = freopen("output.txt", "w", stdout);
#else
	//freopen("bst.in", "r", stdin);
	//freopen("bst.out", "w", stdout);
#endif // DEBUG
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	//--------------------------------------//
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (gcd(a, b) == 1) {
			cout << "Finite" << endl;
		}
		else {
			cout << "Infinite" << endl;
		}
	}
	//-----------------------------------------------//
	return 0;
}