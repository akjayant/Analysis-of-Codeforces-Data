#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pi 3.1415926535897932
#define INF INT_MAX
#define MOD 1000000007

int main() {

	ll t;
	// cin>>t;
	t=1;
	while(t--)
	{
		ll n,i,j,ans=0,c=0,x=-1,y,o,e;
		cin>>n;
		// s=(ll)sqrt(n)+1;
		// ll a[s+1]={0};
		vector<ll>v;
		c=n;
		for(i=2;i*i<=c;++i)
		{
			if(n%i==0)
			{
				v.push_back(i);
				while(n%i==0)
				{
					n/=i;
				}
			}
		}
		if(n>2)v.push_back(n);
		o=0;
		e=0;
		for(auto e1:v){if(e1==1||e1==c)continue;if(e1%2==0)e++;else o++;}
		// cout<<e<<" ";
		// cout<<o<<" ";

		if(e)
		{
			if(o==0)ans=2;
			else ans=1;
		}
		else
		{
			if(o==1)ans=v[0];
			else ans=1;
		}
		if(e==0&&o==0)ans=c;
		cout<<ans;
	}

	return 0;
}