#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll x=0,y=0,a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		if(a%c)
		{
			x=a/c+1;
		}
		else
		{
			x=a/c;
		}
		if(b%d)
		{
			y=b/d+1;
		}
		else
		{
			y=b/d;
		}
		if(x+y>k)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<x<<" "<<y<<endl;
		}
	}
	return 0;
}