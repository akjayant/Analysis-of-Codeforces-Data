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
		ll n;cin>>n;
		string s,t;
		cin>>s>>t;
		map<char,ll>mp;
		vii ans;
		rep(i,0,n)
		{
			mp[s[i]]++;
			mp[t[i]]++;
		}
		bool flag=0;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			if((it->ss) %2)
			{
				cout<<"NO"<<endl;
				flag=1;
				break;
			}
		}
		if(flag)
		continue;

		rep(i,0,n-1)
		{
			if(s[i]==t[i])
			continue;
			flag=0;
			rep(j,i+1,n)
			{
				if(s[i]==s[j])
				{
					ans.pb({j,i});
					swap(t[i],s[j]);
					flag=1;
					break;
				}
				
			}
			
			if(!flag)
			{
				rep(j,i+1,n)
				{
					if(t[j]==s[i])
					{
						bool haha=0;
						rep(h,i+1,n)
						{
							if(s[h]==s[j] && h!=j)
							{
								ans.pb({h,j});
								swap(s[h],t[j]);
								ans.pb({h,i});
								swap(s[h],t[i]);
								haha=1;
								break;
							}
						}
						if(haha==0)
						{
							ans.pb({i+1,j});
							swap(t[j],s[i+1]);
							ans.pb({i+1,i});
							swap(s[i+1],t[i]);
						}
						break;
					}
				}	
			}
		}
		if(ans.size()<=(n+n))
		{
			cout<<"YES"<<endl;
			cout<<ans.size()<<endl;
			rep(i,0,ans.size())
			cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<endl;
		}
		else
		cout<<"NO"<<endl;
	}
}