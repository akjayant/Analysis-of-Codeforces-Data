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

ll fib[100001];
const ll mod = 1e9 + 7;
void setfib() {
	fib[0] = fib[1] = 1;
	for (int i = 2; i < 100001; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
}
int main()
{
	//ofstream cout("outpUt.txt");
	//ifstream cin("inpUt.txt");
	//freopen("outpUt.txt", "w", stdout);
	setfib();
	string s; cin >> s;
	vector<int> ans;
	ll res = 1;
	enum states{nothing, inn, inu};
	states state = nothing;
	int cntn = 0, cntu = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'w' || s[i] == 'm') { res = 0; break; }
		switch (state)
		{
		case nothing:
			if (s[i] == 'n') { cntn++, state = inn; }
			else if(s[i] == 'u'){ cntu++, state = inu; }
			else {  }
			break;
		case inn:
			if (s[i] == 'n') { cntn++; }
			else if (s[i] == 'u') { ans.push_back(cntn); cntn = 0; cntu++, state = inu; }
			else { ans.push_back(cntn); cntn = 0; state = nothing; }
			break;
		case inu:
			if (s[i] == 'n') { ans.push_back(cntu); cntu = 0; cntn++, state = inn; }
			else if (s[i] == 'u') { cntu++; }
			else { ans.push_back(cntu); cntu = 0; state = nothing; }
			break;
		}
	}
	if (cntn)ans.push_back(cntn);
	if (cntu)ans.push_back(cntu);
	for (auto& i : ans) {
		res = (res * fib[i]) % mod;
	}
	cout << res << endl;
}