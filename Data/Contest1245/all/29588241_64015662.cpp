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

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	string x;
	cin >> x;

	int aa = 0;
	int bb = 0;
	int cc = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == 'R')
			aa++;
		if (x[i] == 'P')
			bb++;
		if (x[i] == 'S')
			cc++;
	}
	int aaa = min(b, aa);
	int bbb = min(c, bb);
	int ccc = min(a, cc);
	if ((aaa + bbb + ccc) * 2 < n) {
		cout << "NO" << '\n';
		return;
	}
	a -= ccc;
	b -= aaa;
	c -= bbb;
	//cout << aaa << ' ' << bbb << ' ' << ccc << endl;
	string ans = "";
	for (int i = 0; i < n; i++) {
		if (x[i] == 'R') {
			if (aaa > 0) {
				ans += 'P';
				aaa--;
				continue;
			}
		}
		if (x[i] == 'P') {
			if (bbb > 0) {
				ans += 'S';
				bbb--;
				continue;
			}
		}
		//cout << i + 1 << endl;
		if (x[i] == 'S') {
			if (ccc > 0) {
				ans += 'R';
				ccc--;
				continue;
			}
		}
		if (a > 0) {
			ans += 'R';
			a--;
			continue;
		}
		if (b > 0) {
			ans += 'P';
			b--;
			continue;
		}
		if (c > 0) {
			ans += 'S';
			c--;
			continue;
		}
	}
	cout << "YES" << '\n' << ans << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}