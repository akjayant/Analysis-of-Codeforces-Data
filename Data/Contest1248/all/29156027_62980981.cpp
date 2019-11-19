#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
#include <queue>
#include <iomanip>
#include <stack>
#include <stdio.h>
#include <ctime>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define ever ;;
#define forn(i, k) for(int i = 0; i < k; i++)
#define forin(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);(i)++)
#define forun(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);(i)--)
#define forall(i, v) for( typeof(v.begin()) i = v.begin(); i != v.end() ; i++ )
#define vi vector < int >
#define vll vector < ll >
#define pr pair < int, int >
#define vvi vector < vector < int > >
#define vvll vector < vector < long long > >
#define ios ios_base::sync_with_stdio(0);
#define mp(i,k) make_pair(i,k)
#define all(v) v.begin(),v.end()
#define pb push_back
#define sz(v) int(v.size())
#define belongs(x, c) (find((c).begin(), (c).end(), x) != (c).end())
const ull p1 = 131;
const ull p2 = 129;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int infi = 1e9;
const ll inf = 9223372036854775807;
const ll dd = 1e3 + 7;


template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
	bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
		Pred p;
		return p(left.second, right.second);
	}
};


struct ftree {
	vll B;
	ftree(ll N) : B(vll(N, 0)) {
	}
	void change(int i, int v) {
		B[i] += v;
		ll mask = 1;
		while (true) {
			if (!(i & mask)) {
				i |= mask;
				if (i >= sz(B)) {
					break;
				}
				B[i] += v;
			}
			mask <<= 1;
		}
	}
	ll sum(ll x) {
		ll result = 0;

		for (; x >= 0; x = (x & (x + 1)) - 1) {
			result += B[x];
		}

		return result;
	}
	ll sum(ll l, ll r) {
		if (l) {
			return sum(r) - sum(l - 1);
		}
		else {
			return sum(r);
		}
	}
};
int getFirst(int x) {
	return x % 10;
}
int getLast(int x) {
	while (x >= 10) {
		x /= 10;
	}
	return x;
}
int FindMax(vi a) {
	int maxx = -infi;
	forn(i, (int)a.size()) {
		maxx = max(a[i], maxx);
	}
	return maxx;
}
int FindMin(vi a) {
	int minn = infi;
	forn(i, (int)a.size()) {
		minn = min(a[i], minn);
	}
	return minn;
}
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
string toBinary(int n)
{
	string r;
	while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	return r;
}

int main() {

	ios;
	cin.tie(0);
	cout.tie(0);
	//примите пожалуйста
	//ifstream cin("input.in");
	//ofstream cout("output.txt");
	//srand(time(0));
	int t;
	cin >> t;
	forn(i, t) {
		ll n;
		cin >> n;
		vi a(n);
		ll odd = 0, even = 0;
		forn(i, n) {
			cin >> a[i];
			if (a[i] % 2 == 0) even++;
			else odd++;
		}
		ll odd1 = 0, even1 = 0;
		ll n1;
		cin >> n1;
		vi b(n1);
		forn(i, n1) {
			cin >> b[i];
			if (b[i] % 2 == 0) even1++;
			else odd1++;
		}
		cout << even1 * even + odd * odd1 << endl;
	}
	//cout << endl<< "runtime = " << clock() / 1000.0 << endl;
	//cout.close();
	return 0;
}






