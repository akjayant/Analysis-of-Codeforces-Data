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
	for (ll j = 0; j < a; ++j)
	{
		ll n;
		cin >> n;
		ar.resize(0);
		ar.resize(n);
		for (ll i = 0; i < n; ++i)
			cin >> ar[i];
		sort(ar.begin(), ar.end());
		ll k = 0;
		for (ll i = n - 1; i >= 0; --i)
		{
			if (ar[i] >= n - i)
			{
				k = n - i;
			}		
		}
		cout << k << endl;
	}
}