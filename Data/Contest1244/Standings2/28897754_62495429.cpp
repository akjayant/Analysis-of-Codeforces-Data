#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

long long b[100004];

vector <pair <long long, long long>> a;



int main()
{
	long long n;
	long long k;
	cin >> n >> k;
	
	for(long long i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	
	sort(b, b + n);
	
	a.push_back(make_pair(b[0], 1));
	
	for(int i = 1; i < n; i++)
	{
		if(a[a.size() - 1].f == b[i])
		{
			a[a.size() - 1].s++;
		}
		else
		{
			a.push_back(make_pair(b[i], 1));
		}
	}
	
	long long l = 0;
	long long r = a.size() - 1;
	
	while(l != r && k > 0)
	{
		if(a[l].s <= a[r].s)
		{
			if(k >= a[l].s * (a[l + 1].f - a[l].f))
			{
				k -= a[l].s * (a[l + 1].f - a[l].f);
				a[l + 1].s += a[l].s;
			}
			else
			{
				cout << a[r].f - (a[l].f + (k / a[l].s));
				return 0;
			}
			l++;
		}
		else
		{
			if(k >= a[r].s * (a[r].f - a[r - 1].f))
			{
				k -= a[r].s * (a[r].f - a[r - 1].f);
				a[r - 1].s += a[r].s;
			}
			else
			{
				cout << (a[r].f - (k / a[r].s)) - a[l].f;
				return 0;
			}
			r--;
		}
		
		if(k == 0)
		{
			cout << a[r].f - a[l].f;
			return 0;
		}
	}
	
	cout << 0;
	
	return 0;
}