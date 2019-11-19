#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
//#define p pair<ll,ll>
#define MAX 15000001
#define vc vector<char>
int LIM=110;
vv dp(LIM,v(LIM,1e9));
vv adj(110);
int n;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    int f=0;
    for (int i=0; i<=d; i++)
    {
    	ll temp=w*i;
    	ll rem=p-temp;
    	if (rem<0)
    	{
    		cout<<-1<<endl;
    		return 0;
    	}
    	if (rem%d==0)
    	{
    		ll y=rem/d;
    		if (i+y<=n)
    		{
    			cout<<i<<" "<<y<<" "<<n-i-y<<endl;
    			return 0;
    		}
    		ll c=(i+y)-n;
			ll lcm=w*d/__gcd(w,d);
			ll a=lcm/w;
			ll b=lcm/d;
			ll diff=b-a;
			ll e=c/diff;
			if (c%diff!=0)
			{
				e++;
			}    	
			ll x1=i+e*a;
			ll x2=y-e*b;
			if (x1>=0 && x2>=0 && x1+x2<=n)
			{
				cout<<x1<<" "<<x2<<" "<<n-x1-x2<<endl;
				return 0;
			}	
    	}
    }
    cout<<-1<<endl;
    return 0;   
} 