#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<fstream>
#include<queue>
#include<iostream>
#include<unordered_map>
#include<math.h>
#include<stack>
#include <numeric>
#include<iomanip>
#include<unordered_set>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
const int maxm = 305;
ll arr[maxn];
ll arr1[maxn];
const ll mod = 1e9 + 7;
vector<ll> edges[maxn];
ll n, m, k, q, D, H, a, b, c, h, d, x, y, z, t,p;
string s, s1, s2;
ll gcd(ll a, ll b)
{
	ll t;
	while (b)
	{
		t = a;
		a = b;
		b = t % b;
	}
	return a;
}
ll par[maxn];
void init() {
	for (int i = 0; i < maxn; i++)
		par[i] = i;
}
void init(int n) {
	for (int i = 0; i < n+10; i++)
		par[i] = i;
}
ll find(int i) {
	if (par[i] != i) {
		return par[i] = find(par[i]);
	}
	else
		return i;
}
void merge(int x, int y) {
	par[find(x)] = par[find(y)];
}
ll presum[100];
bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
};

vector<int> get_pi(const string s) {
	int n = s.length();
	vector<int> pi(n);
	int k = 0;
	for (int i = 1; i < n; i++) {
		while (k > 0 && s[i] != s[k])
			k = pi[k - 1];
		if (s[i] == s[k])
			k++;
		pi[i] = k;
	}
	return pi;
}

ll dp[maxn];

struct Node {
	ll x;
	ll y;
	ll id;
} nodes[2010];
ll cc[2010];
ll kk[2010];
struct Segment {
	Segment() {}
	Segment(ll _from, ll _to, ll _cost) { from = _from; to = _to; cost = _cost; }
	ll from;
	ll to;
	ll cost;
};

bool cmp(Segment s1, Segment s2) {
	return s1.cost < s2.cost;
}
int main() {
	cin >> n;
	init();
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i].x >> nodes[i].y;
		nodes[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> cc[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> kk[i];
	}
	vector<Segment> edges;
	for (int i = 1; i <= n; i++) {
		edges.push_back(Segment(0, i, cc[i]));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edges.push_back(Segment(i, j, (abs(nodes[i].x - nodes[j].x) + abs(nodes[i].y - nodes[j].y))*(kk[i] + kk[j])));
		}
	}
	sort(edges.begin(), edges.end(), cmp);
	vector<Segment> ans;
	ll totalcost = 0;
	for (auto se : edges) {
		int from = se.from;
		int to = se.to;
		if (find(from) != find(to)) {
			merge(from, to);
			ans.push_back(se);
			totalcost += se.cost;
		}
	}
	cout << totalcost << endl;
	int cnt = 0;
	for (auto se : ans) {
		if (se.from == 0) {
			cnt++;
		}
	}
	cout << cnt << endl;
	for (auto se : ans) {
		if (se.from == 0) {
			cout << se.to << " ";
		}
	}
	cout << endl;
	cout << ans.size() - cnt << endl;
	for (auto se : ans) {
		if (se.from != 0) {
			cout << se.from << " " << se.to << endl;
		}
	}
}