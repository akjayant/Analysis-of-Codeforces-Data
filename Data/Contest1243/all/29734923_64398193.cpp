#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <set>

using namespace std;
using ll = long long;


#define SZ(a) a.size()
#define pb(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define mp(a,b) make_pair(a,b)

const ll mod = 1000000000 + 7;

int main() 
{
	//ifstream cin("input.txt");
	set <ll> del;
	ll n;
	cin >> n;
	vector <ll> ans;
	ll N = n;
	for (ll i = 2; i * i < n + 15; i++)
	{
		if (n % i == 0)
		{
			ans.pb(i);
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}
	if (n != 1 && n != N)
	{
		ans.pb(n);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		del.insert(ans[i]);
	}
	if (del.size()==0)
	{
		cout << N;
		return 0;
	}
	if (del.size() == 1)
	{
		cout << (*del.begin());
		return 0;
	}
	cout << 1;
	
	return 0;
}