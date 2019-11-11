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

//#define x first
//#define y second
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

li gcd(li a,li b)
{
	return b ? gcd(b, a % b) : a;
}

void solve()
{
	int n;
	int a, b, c;
	cin >> n;
	cin >> a >> b >> c;
	string s;
	cin >> s;
	int p, q, r;
	p = count(all(s), 'R');
	q = count(all(s), 'P');
	r = count(all(s), 'S');
	int a1 = min(a, r);
	int b1 = min(b, p);
	int c1 = min(c, q);
	if (a1 + b1 + c1 < n / 2 + n % 2)
	{
		cout << "NO" << endl;
		return;
	}
	string w = string(a - a1, 'R') + string(b - b1, 'P') + string(c - c1, 'S');
	string res(n,' ');
	forn(i, n)
	{
		if (s[i] == 'R' && b1 > 0)
		{
			b1--;
			res[i] = 'P';
			continue;
		}
		if (s[i] == 'P' && c1 > 0)
		{
			c1--;
			res[i] = 'S';
			continue;
		}
		if (s[i] == 'S' && a1 > 0)
		{
			a1--;
			res[i] = 'R';
			continue;
		}
		res[i] = w.back();
		w.pop_back();
	}
	cout << "YES" << endl << res << endl;
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