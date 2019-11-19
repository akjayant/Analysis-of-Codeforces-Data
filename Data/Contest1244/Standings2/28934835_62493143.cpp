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
#include <ctime>
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

int main()
{
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	li n, k;
	cin >> n >> k;
	map<li,li> mp;
	forn(i, n)
	{
		li v;
		cin >> v;
		mp[v]++;
	}
	while (mp.size() > 1 && k)
	{
		pi mn = *(mp.begin());
		pi mx = *(mp.rbegin());

		if (mn.y < mx.y)
		{
			mp.erase(mn.x);
			li v = mp.begin()->first;

			li d = min(k, (v - mn.x) * mn.y);
			mn.x += d / mn.y;
			k -= d;
			mp[mn.x] += mn.y;
		}
		else
		{
			mp.erase(mx.x);
			li v = mp.rbegin()->first;

			li d = min(k, (mx.x - v) * mx.y);
			mx.x -= d / mx.y;
			k -= d;
			mp[mx.x] += mx.y;
		}
	}
	cout << mp.rbegin()->first - mp.begin()->first << endl;
}