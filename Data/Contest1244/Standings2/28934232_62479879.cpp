#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MAXN 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	ll a = p%w;
	ll y = 0;
	while((y*d)%w != a && y!=w)
		++y;
	if(y==w)
		cout<<-1<<endl;
	else
	{
		ll x = (p-y*d)/w;
		if(x>=0 && x+y<=n)
			cout<<x<<" "<<y<<" "<<n-x-y<<endl;
		else
		{
			cout<<-1<<endl;
		}
		
	}
	
		
	return 0;
}
