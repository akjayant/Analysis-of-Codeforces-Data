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

void solve() {
	int n;
	cin >> n;
	string a;
	cin >> a;
	int p1, p2;
	p1 = -1;
	p2 = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') {
			if (p1 == -1)
				p1 = i;
			p2 = max(p2, i);
		}
	}
	if (p1 == -1 && p2 == -1) {
		cout << n << '\n';
		return;
	}
	int ans1 = (p2 + 1) * 2;
	int ans2 = (n - p1) * 2;
	int ans3 = n + 1;
	cout << max(ans1, max(ans2, ans3)) << '\n';
}
 
signed main()
{
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int q;
	cin >> q;

	while (q--)
		solve();
	
	return 0;
}