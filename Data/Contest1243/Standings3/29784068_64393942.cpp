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

	vector<set<li>> a(30),b(30);
	vi num(30, 0);
	forn(i, n)
	{
		a[s[i] - 'a'].insert(i);
		b[t[i] - 'a'].insert(i);
		num[s[i] - 'a']++;
		num[t[i] - 'a']++;
	}
	forn(i, 30)
		if (num[i] % 2)
		{
			cout << "No" << endl;
			return;
		}

	vpi res;

	auto swap_a = [&](int pos)
	{
		if (b[t[pos] - 'a'].empty())
			return 0;
		int ind = *(b[t[pos] - 'a'].begin());
		b[t[pos] - 'a'].erase(b[t[pos] - 'a'].begin());
		b[s[pos] - 'a'].insert(ind);
		t[ind] = s[pos];
		res.emplace_back(pos + 1, ind + 1);
		return 1;
	};

	auto swap_b = [&](int pos)
	{
		int ind = *(a[t[pos] - 'a'].begin());
		a[t[pos] - 'a'].erase(a[t[pos] - 'a'].begin());
		a[s[pos] - 'a'].insert(ind);
		s[ind] = s[pos];
		res.emplace_back(pos + 1, pos + 1);
		res.emplace_back(ind + 1, pos + 1);
	};

	forn(i, n)
	{
		a[s[i] - 'a'].erase(i);
		b[t[i] - 'a'].erase(i);
		if (s[i] == t[i])
			continue;
		if (!swap_a(i))
			swap_b(i);
	}
	cout << "Yes" << endl;
	cout << res.size() << endl;
	for (auto p : res)
		cout << p.first << " " << p.second << endl;
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