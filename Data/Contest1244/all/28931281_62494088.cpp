#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) ((int)x.size())

typedef long long ll;
typedef long double ld;

using namespace std;

namespace IO {
#define AUTO_T template <typename T>
#define AUTO_TT template <class T1, class T2>
	AUTO_T ostream& operator << (ostream& out, vector <T>& p) {
		for (auto& el : p)
			out << el << ' ';
		return out;
	}
	AUTO_T istream& operator >> (istream& inp, vector <T>& p) {
		for (auto& el : p)
			inp >> el;
		return inp;
	}
	AUTO_T ostream& operator << (ostream& out, deque <T>& p) {
		for (auto& el : p)
			out << el << ' ';
		return out;
	}
	AUTO_T istream& operator >> (istream& inp, deque <T>& p) {
		for (auto& el : p)
			inp >> el;
		return inp;
	}
	AUTO_TT ostream& operator << (ostream& out, pair <T1, T2>& p) {
		out << p.f << ' ' << p.s << endl;
		return out;
	}
	AUTO_TT istream& operator >> (istream& inp, pair <T1, T2>& p) {
		inp >> p.f >> p.s;
		return inp;
	}
}
using namespace IO;

const ll M1 = 1e9 + 7;
const ll M2 = 1e9 - 7;
const ll B1 = 29;
const ll B2 = 73;
const ll INF = 4e18;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll n, k;
vector <ll> a;

ll c1(ll p, ll m) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= p && a[i] <= p + m)
			continue;
		if (a[i] < p)
			sum += abs(a[i] - p);
		if (a[i] > p + m)
			sum += abs(p + m - a[i]);
	}
	return k - sum;
}

bool check(ll m) {
	ll l = a.back();
	ll r = a[0];
	while (r - l > 2) {
		ll m1 = (l * 2 + r) / 3;
		ll m2 = (r * 2 + l) / 3;
		if (c1(m1, m) < c1(m2, m))
			l = m1;
		else
			r = m2;
	}
	for (ll i = l; i <= r; i++)
		if (c1(i, m) >= 0)
			return true;
	return false;
}
 
signed main()
{
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	cin >> n >> k;
	a.resize(n);
	cin >> a;
	sort(rall(a));

	ll l = -1;
	ll r = abs(a[0] - a.back());

	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}

	cout << r;
	
	return 0;
}