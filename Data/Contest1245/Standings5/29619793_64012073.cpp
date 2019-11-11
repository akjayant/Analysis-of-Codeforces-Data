#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;

char ans[5] = "RPS";
vector <int> seq;
void solve()
{
	int n;
	cin >> n;
	seq.clear();
	seq.resize(n);
	for (int i = 0; i<n; i++)
		seq[i] = -1;
	int a, b, c;
	cin >> a >> b >> c;
	string bob;
	cin >> bob;
	int maxwin = 0;
	for (int i = 0; i<bob.size(); i++)
	{
		if (bob[i] == 'R' && (b > 0))
		{
			seq[i] = 1; b--;
			maxwin++;
		}
		else if (bob[i] == 'P' && (c > 0))
		{
			seq[i] = 2; c--;
			maxwin++;
		}
		else if (bob[i] == 'S' && (a > 0))
		{
			seq[i] = 0; a--;
			maxwin++;
		}
	}
	if (maxwin*2 >= n)
	{
		cout << "YES\n";
	}
	else
	{	cout << "NO\n";
		return;
	}
	for (int i = 0; i<n; i++)
	{
		if (seq[i]==-1)
		{
			if (a)
			{
				seq[i] = 0; 
				a--;
			}
			else if (b)
			{
				seq[i] = 1; 
				b--;
			}
			else if (c)
			{
				seq[i] = 2; 
				c--;
			}
		}
	}
	for (int i = 0; i<n; i++)
		cout << ans[seq[i]];
	cout << '\n';
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}