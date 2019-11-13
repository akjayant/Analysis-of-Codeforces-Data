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

const li M = 1e9 + 7;

int main()
{
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size();

	vi fib(1e5 + 10);
	forn(i, fib.size())
		fib[i] = i < 2 ? 1 : (fib[i - 1] + fib[i - 2]) % M;

	li res = 1;
	li k = 0;
	forn(i, n)
	{
		k++;
		if (i == n - 1 || s[i] != s[i + 1])
		{
			if (s[i] == 'u' || s[i] == 'n')
			{
				res *= fib[k];
				res %= M;
			}
			k = 0;
		}
		if (s[i] == 'm' || s[i] == 'w')
			res = 0;
	}
	cout << res << endl;
}