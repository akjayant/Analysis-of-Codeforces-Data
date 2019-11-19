//stack size is 50MB
#define _CRT_SECURE_NO_WARNINGS
#include<list>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<fstream>
#include<cstring>
#include<list>
#include <queue>

#define fr(j,k) for(int i = 0; i < k; i++)
#define rfr(j,k) for(int i = k; i >= 0; i--)
using ll = long long;
using ull = unsigned long long int;
using ld = long double;
using namespace std;
using vll = vector<ll>;
# define PI acos(ld(-1))
ll egcd(ll a, ll b, ll& x, ll& y) {//ax + by = gcd(a,b)
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	ll ans = egcd(b, a % b, x, y);
	ll p = x, q = y;
	x = q;
	y = p - a / b * q;
	return ans;
}
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
ll lcm(ll x, ll y) {
	return x * y / gcd(x, y);
}

struct CITY{
	ll x, y;
	ll k;
	ll index;
	ll srcindex;
	ll cost;
};
bool cmp(CITY a, CITY b) {
	return a.cost > b.cost;//head is acually min not max
}
ll runroad(CITY a, CITY b) {
	return (a.k + b.k) * (abs(a.x - b.x) + abs(a.y - b.y));
}
int main()
{
	//ofstream cout("outpUt.txt");
	//ifstream cin("inpUt.txt");
	//freopen("outpUt.txt", "w", stdout);
	vector<CITY> cities;
	vector<CITY> ans;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		CITY c;
		cin >> c.x >> c.y;
		cities.push_back(c);
		cities[i].index = i + 1;
		cities[i].srcindex = i + 1;
	}

	fr(i, n) {
		cin >> cities[i].cost;
	}
	fr(i, n) {
		cin >> cities[i].k;
	}
	for (int i = 0; i < n; i++) {
		make_heap(cities.begin(), cities.end(), cmp);
		pop_heap(cities.begin(), cities.end(), cmp);
		ans.push_back(cities.back()); cities.pop_back();
		for (int i = 0; i < cities.size(); i++) {
			ll tmpcost = runroad(ans.back(), cities[i]);
			if (tmpcost < cities[i].cost) {
				cities[i].cost = tmpcost;
				cities[i].srcindex = ans.back().index;
			}
		}
	}
	ll fcost = 0;
	int build = 0;
	for (auto& c : ans)
		fcost += c.cost, build += c.index == c.srcindex;
	cout << fcost << endl;

	cout << build << endl;
	for (auto& c : ans)
		if (c.index == c.srcindex)
			cout << c.index << " ";
	cout << endl;

	cout << n - build << endl;
	for (auto& c : ans)
		if (c.index != c.srcindex)
			cout << c.index << " " << c.srcindex << endl;
}