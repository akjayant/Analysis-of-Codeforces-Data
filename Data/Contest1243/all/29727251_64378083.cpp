#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define nl cout<<endl

#define pii pair<ll,ll>
#define vi  vector<ll>
#define vii vector<pii>
#define mi  map<ll,ll>
#define all(a)  (a).begin(),(a).end()

#define pb push_back
#define ff first
#define ss second
#define hell 1000000007

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;
#define N 300009

ll power(ll a,ll b,ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
        ll t;cin>>t;
	while(t--)
	{
		vi v;
		ll n;cin>>n;
		string a,b;cin>>a>>b;
		rep(i,0,n)
		{
			if(a[i]!=b[i])
			v.pb(i);
		}
		if(v.size()==0)
		cout<<"YES"<<endl;
		else if(v.size()==2)
		{
			string s1=a,s2=b;
			char c1=s1[v[0]];
			char c2=s2[v[1]];
			s1[v[0]]=c2;
			s2[v[1]]=c1;
			if(s1==s2)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				s1=b,s2=a;
				char c1=s1[v[0]];
				char c2=s2[v[1]];
				s1[v[0]]=c2;
				s2[v[1]]=c1;
				if(s1==s2)
				cout<<"YES"<<endl;
				else
				cout<<"NO"<<endl;
			}
		}
		else
		cout<<"NO"<<endl;
	}
}