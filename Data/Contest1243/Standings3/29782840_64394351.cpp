#include <bits/stdc++.h>
#define intt long long 
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pil pair<int,intt>
#define pli pair<intt,int>
#define pll pair<intt,intt>
using namespace std;
bool is_prime( intt n )
{
	if ( n == 2 or n == 3 )
		return true;
	if ( n%2==0 or n%3==0 )
		return false;
	for ( intt i = 5,t=2; i * i <= n; i+= t,t=6-t )
	{
		if ( n%i == 0 )
			return false;
	}
	return true;
}
intt i,j;
int main()
{
	intt n;
	cin >> n;
	if ( n == 1 or is_prime(n) )
	{
		cout << n << endl;
		return 0;
	}
	vector<intt>v;
	for ( i = 2; i * i <= n; i++ )
	{
		if ( n%i==0 )
		{
			v.pb(i);
			while ( n%i==0 )
			{
				n/=i;
			}
		}
	}
	if ( n > 1 )
		v.pb(n);
	if ( v.size() > 1 )
	{
		cout << 1 << endl;
		return 0;
	}
	cout << v.back() << endl;
}