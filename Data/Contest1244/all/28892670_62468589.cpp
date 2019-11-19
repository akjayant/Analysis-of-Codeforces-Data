#include <iostream>
// Author: MrLolthe1st
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
#define vec vector
#define ms multiset
#define pb push_back
#define pll pair<long long, long long>
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define int long long
#define _ << " " <<
#define all(a) a.begin(), a.end()
#define srt(a) std::sort(a.begin(), a.end())
template<typename T>
vector<T> _set_to_vec(std::set<T> z)
{
	vector<T> w;
	auto it = z.begin();
	while (it != z.end())
		w.push_back(*it++);
	return w;
}
template<typename T>
void pop_front(std::vector<T>& vec)
{
	vec.erase(vec.begin());
}

vector<long long> z_function(string s) {
	long long n = (long long)s.length();
	vector<long long> z(n);
	for (long long i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}
struct point {
	double x, y;
	point(double x, double y) :x(x), y(y) {};
	point() {};
};

point operator+(point a, point b) { return point(a.x + b.x, a.y + b.y); };
point operator-(point a, point b) { return point(a.x - b.x, a.y - b.y); };
double operator*(point a, point b) { return (a.x * b.x + a.y * b.y); };

double operator^(point a, point b) { return (a.x * b.y - a.y * b.x); };
double operator%(point a, point b) { return atan2(a ^ b, a * b); }
double eps = 1e-13;
template<typename T>
bool equals(T a, T b)
{
	return abs(a - b) <= eps;
}
template<typename T>
int sign(T a)
{
	return a < 0 ? -1 : (a > 0 ? 1 : 0);
}
#define pt point
inline double area(pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
inline char intersect_1(double a, double b, double c, double d) {
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return max(a, c) <= min(b, d);
}

char intersect(pt a, pt b, pt c, pt d) {
	return intersect_1(a.x, b.x, c.x, d.x)
		&& intersect_1(a.y, b.y, c.y, d.y)
		&& area(a, b, c) * area(a, b, d) <= 0
		&& area(c, d, a) * area(c, d, b) <= 0;
}

double pi = acos(-1.0);
double dist(point p)
{
	return sqrt(p.x * p.x + p.y * p.y);
}

bool cmpr(pt a, pt b)
{
	if (equals((a ^ b), (double)0))
		return dist(a) < dist(b);
	else return (a ^ b) < 0;
}
bool cmp(pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw(pt a, pt b, pt c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void convex_hull(vector<pt>& a) {
	if (a.size() == 1)  return;
	sort(a.begin(), a.end(), &cmp);
	pt p1 = a[0], p2 = a.back();
	vector<pt> up, down;
	up.push_back(p1);
	down.push_back(p1);
	for (size_t i = 1; i < a.size(); ++i) {
		if (i == a.size() - 1 || cw(p1, a[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
				up.pop_back();
			up.push_back(a[i]);
		}
		if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
				down.pop_back();
			down.push_back(a[i]);
		}
	}
	a.clear();
	for (size_t i = 0; i < up.size(); ++i)
		a.push_back(up[i]);
	for (size_t i = down.size() - 2; i > 0; --i)
		a.push_back(down[i]);
}

typedef string str;

template<typename T>
inline istream& operator >>(istream& in, vec<T>& a) {
	for (int i = 0; i < a.size(); i++) in >> a[i];
	return in;
}

template<typename T>
inline ostream& operator <<(ostream& out, vec<T>& a) {
	for (int i = 0; i < a.size(); i++) out << a[i] << " ";
	return out;
}

template<typename T, typename E>
inline istream& operator >>(istream& in, pair<T, E>& a) {
	in >> a.first >> a.second;
	return in;
}

template<typename T>
T gcd(T a, T b) {
	T c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

template<typename T>
T lcm(T a, T b) {
	return (a / gcd(a, b)) * b;
}


vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int binpow(int a, int n) {
	if (n == 0)
		return 1;
	if (n & 1)
		return binpow(a, n - 1) * a;
	else {
		int b = binpow(a, n >> 1);
		return b * b;
	}
}

vector<int> primes(int N) {
	vector<int> lp(N + 1);
	vector<int> pr;

	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
	return pr;
}


typedef vec<vi> matrix;

matrix operator*(matrix& a, matrix& b) {
	matrix m;
	int cx = a[0].size(), cy = b.size();
	m.resize(cx);
	for (int i = 0; i < cx; i++)
		m[i].resize(cy);
	for (int i = 0; i < cx; i++) {
		for (int j = 0; j < cy; j++) {
			int res = 0;
			for (int p = 0; p < b[0].size(); p++)
				res += a[i][p] * b[p][j];
			m[i][j] = res;
		}
	}
	return m;
}

int cnt = 0;
matrix pow(matrix& a, int b) {
	if (b == 1)
		return a;
	cnt++;
	if (b & 1)
	{
		auto r = pow(a, b - 1);
		r = r * a;
		return r;
	}
	else {
		auto r = pow(a, b / 2);
		r = r * r;
		return r;
	}
}
set<int> printDivisors(int n)
{
	set<int> r;
	// Note that this loop runs till square root 
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			// If divisors are equal, print only one 
			if (n / i == i)
				r.insert(i);

			else // Otherwise print both 
				r.insert(i), r.insert(n / i);
		}
	}
	return r;
}
#include <sstream>
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
map<int, int> dp;

vi p;
int slv(int from, int x) {
	if (from >= p.size()) return 0;
	int cs = x < p.size() ? p[x] : 0;
	int w = p[from] - cs;
	int cnt0 = w / 3;
	int r = cnt0 + min(slv(x, x + 1), slv(x, x + 2));
	dp[x] = r;
	return r;
}

int solve1(vi a) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
		for (int j = i; j < a.size(); j++) {
			int mn = a[i];
			int mx = a[i];
			for (int k = i; k <= j; k++)
				mn = min(a[k], mn), mx = max(mx, a[k]);
			if (mx - mn == j - i)
				cnt++;
		}
	return cnt;
}

int solve_fast(vi a) {

	int cnt = a.size();
	for (int i = 0; i < a.size() - 1; i++) {
		int r = abs(a[i] - a[i + 1]) - 1;
		int ml = max(0ll, i - r);
		int mr = min(a.size() - 1ll, i + r);
		cnt += abs(mr - ml);
	}
	return cnt;

}

inline void solve() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int last = -1;
		int first = -1;
		for (int i = 0; i < n; i++)
			if (s[i] == '1') {
				last = i;
				if (first == -1)
					first = i;
			}
		if (last == -1)
			cout << n;
		else cout << max((n - first) * 2, max(n, (last + 1) * 2));
		cout << "\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	int k;
	cin >> k;
}
