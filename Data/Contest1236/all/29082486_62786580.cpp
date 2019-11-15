#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    	ll a,b,c;
    	ll ans1=0,ans2=0;
    	cin>>a>>b>>c;
    	while(1)
    	{
    		if(b>=1 && c>=2)
    		{
    			b--;
    			c-=2;
    			ans1+=3;
    		}
    		else
    			break;
    	}
    	while(1)
    	{
    		if(a>=1 && b>=2)
    		{
    			a--;
    			b-=2;
    			ans1+=3;
    		}
    		else
    			break;
    	}
    	cout<<ans1<<endl;
    }
    return 0;
}