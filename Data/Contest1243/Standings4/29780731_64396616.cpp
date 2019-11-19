#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("fast-math")
 
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
#include <map>
 
#define ll long long
#define S second
#define F first
 
using namespace std;
 
ll a, b, c, d, e, f, cycle, st, ot, k;
vector <vector <ll> > arr, arr1;
vector <ll> ar;
 
 
 
ll nod(ll a, ll b)
{
	if (b == 0)
		return a;
	return nod(b, a % b);
}


 
 
int main()
{
	cin >> a;
	vector <ll> pp;
	for (ll i = 2; i <= round(sqrt(a)); ++i)
	{
		if (a % i == 0)
			pp.push_back(i);
		if (a % i == 0 && a / i != i)
			pp.push_back(a / i);
	}
	if ((ll)pp.size() == 0)
	{
		cout << a << endl;
		return 0;
	}
	ll k = pp[0];
	for (ll i = 1; i < pp.size(); ++i)
	{
		k = nod(max(pp[i], k), min(k, pp[i]));
	}
	cout << k << endl;
	return 0;
}
