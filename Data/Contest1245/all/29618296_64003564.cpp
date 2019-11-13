#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <map>
#include <list>
#include<set>
using namespace std;

#define FOR(n) for(int i=0;i<n;++i)
#define FORj(n) for(int j=0;j<n;++j)
#define pb push_back
#define ll long long
#define vecI vector<int> 
#define vecII vector<vector<int>>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)

int main()
{
	int a, b, c,n,t,x,y,z;
	string s;
	cin >> t;
	while (t--)
	{
		cin >>n>> a >> b >> c;
		x = y = z = 0;
		cin >> s;
		FOR(size(s))if (s[i] == 'R')x++;
		else if (s[i] == 'P')y++;
		else z++;
		if ((min(a, z) + min(b, x) + min(c, y)) * 2 < n)cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			FOR(size(s)) if (s[i] == 'R')
			{
				if (b > 0)
				{
					cout << 'P';
					x--;
					b--;
				}
				else if (c > y)
				{
					cout << 'S';
					c--;
					x--;
				}
				else
				{
					cout << 'R';
					x--;
					a--;
				}
			}
			else if (s[i] == 'P')
			{
				y--;
				if (c > 0)
				{
					cout << 'S';
					c--;
				}
				else if (b > x)
				{
					cout << 'P';
					b--;
				}
				else
				{
					cout << 'R';
					a--;
				}
			}
			else
			{
				z--;
				if (a > 0)
				{
					cout << 'R';
					a--;
				}
				else if (b > x)
				{
					cout << 'P';
					b--;
				}
				else
				{
					cout << 'S';
					c--;
				}
			}
		}
		cout << endl;
	}
}