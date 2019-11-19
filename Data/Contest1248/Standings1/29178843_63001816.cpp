#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define MOD 1000000007 
#define INF 1000000000000000000
#define uid uniform_int_distribution <int>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int check(string s)
{
	int n = (int) s.size();
	int c1 = 0, p1 = -1, r1 = 0;
	for (int i = 0; i < n; i++)
	{
		if(s[i] == ')')
		{
			if(c1 > 0)
			{
				c1--;
			}
			else
			{
				r1++;
				p1 = i;
			}
		}
		else
			c1++;
	}
	int c2 = 0, p2 = n + 1, r2 = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if(s[i] == '(')
		{
			if(c2 > 0)
			{
				c2--;
			}
			else
			{
				r2++;
				p2 = i;
			}
		}
		else
			c2++;
	}
	//cerr << s << "\n";
	//cerr << p1 << " " << p2 << "\n";
	assert(p1 < p2);
	if(r1 != r2)
		return 0;
	string t = s.substr(p1 + 1) + s.substr(0, p1 + 1);
	//cerr << t << "\n";
	int c = 0, beauty = 0;
	for (int i = 0; i < n; i++)
	{
		if(t[i] == '(')
		{
			c++;
		}
		else
		{
			c--;
		}
		assert(c >= 0);
		beauty += (c == 0);
	}
	return beauty;
}
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <int> l, r;
	for (int i = 0; i < n; i++)
	{
		if(s[i] == '(')
		{
			l.push_back(i);
		}
		else
		{
			r.push_back(i);
		}
	}
	int ans = check(s), pl = 1, pr = 1;
	for (int i = 0; i < (int) l.size(); i++)
	{
		for (int j = 0; j < (int) r.size(); j++)
		{
			swap(s[l[i]], s[r[j]]); 
			int b = check(s);
			if(b > ans)
			{
				ans = b;
				pl = l[i] + 1;
				pr = r[j] + 1;
			}
			swap(s[l[i]], s[r[j]]);
		}
	}
	cout << ans << "\n";
	cout << pl << " " << pr << "\n";
}
