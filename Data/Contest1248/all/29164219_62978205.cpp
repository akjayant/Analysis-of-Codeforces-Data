#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t)
    {
    	t--;
    	ll n, m;
    	cin >> n;
    	ll eve1=0, eve2=0, odd1=0, odd2=0;
    	for (int i = 0; i < n; ++i)
    	{
    		ll x;
    		cin >>x;
    		if(x%2)
    		{
    			eve1++;
    		} 
    		else
    		{
    			odd1++;
    		}
    	}
    	cin >> m;
    	for (int i = 0; i < m; ++i)
    	{
    		ll x;
    		cin >> x;
    		if(x%2)
    		{
    			eve2++;
    		} 
    		else
    		{
    			odd2++;
    		}
    	}
    	cout << (eve1)*eve2+odd2*odd1<<"\n";
    }
    return 0;
}