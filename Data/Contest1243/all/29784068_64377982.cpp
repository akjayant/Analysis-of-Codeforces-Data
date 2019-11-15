#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <random>
#include <climits>
#include <iomanip>
#include <queue>
#include <bitset>
#include <cctype>
#include <ostream>
#include <functional>
#include <complex>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <deque>
#include <numeric>

using namespace std;

typedef long long li;

#define forn(i,n) for (li i = 0;i < li(n);i++)
#define ford(i,n) for (li i = li(n)-1;i >=0;i--)
#define fore(i,l,r) for (li i = li(l);i < li(r);i++)
#define correct(x,n) (((x) >= 0) && ((x) < n))
#define mp(a,b) make_pair((a),(b))
#define all(a) (a).begin(),(a).end()
#define rnd() (rand() + (RAND_MAX+1)*rand())
//#define DEBUG_

#define x first
#define y second
//#define x real()
//#define y imag()

typedef vector<li> vi;
typedef pair<li, li> pi;
typedef vector<pi> vpi;
typedef vector<vector<li>> vvi;
typedef long double ld;
typedef pair<li, li> Point;
//typedef complex<li> Point;
//typedef complex<ld> Point;

void solve()
{
	li n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vpi a;
	forn(i, n)
		if (s[i] != t[i])
			a.emplace_back(s[i], t[i]);
	if (a.size() > 2)
	{
		cout << "No" << endl;
		return;
	}
	if (a.empty())
	{
		cout << "Yes" << endl;
		return;
	}
	if (a.size() == 1 && a[0].first == a[0].second)
	{
		cout << "Yes" << endl;
		return;
	}
	if (a.size() == 2 && a[0] == a[1])
	{
		cout << "Yes" << endl;
		return;
	}
	cout << "No" << endl;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	forn(i, n)
		solve();
}