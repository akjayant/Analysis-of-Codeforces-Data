#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pp pair<ll,ll>
#define pq_min priority_queue<ll,vector<ll>,greater<ll>>
#define pq_max priority_queue<ll>
#define forx(i,a,b) for(ll i=0;i<a;i++)
#define ld long double
const ll mod=1e9 + 7;

ll power(ll a,ll b)
{
	a=a%mod;
	ll ans=1;
	while(b>0)
	{
		if(b%2==1)
		{
			ans=(ans*a)%mod;
		}
		b=b/2;
		a=(a*a)%mod;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
	 ll n;
	 cin>>n;
	 string s;
	 cin>>s;
	 string h;
	 cin>>h;
	 ll a[26]={0};
	 set<ll> fi[26];
	 set<ll> se[26];
	 for(ll i=0;i<n;i++)
	 {
	 	a[s[i]-97]++;
	 	a[h[i]-97]++;
	 	fi[s[i]-97].insert(i);
	 	se[h[i]-97].insert(i);
	 }
	 ll f=0;
	 for(ll i=0;i<26;i++)
	 {
	 	if(a[i]%2==1)
	 	{
	 	   f=1;
		   break;	
		}
	 }
	 if(f==1)
	 {
	 	cout<<"No"<<endl;
	 }
	 else
	 {
	 	vector<pp> p;
	 	cout<<"Yes"<<endl;
	 	for(ll i=0;i<n;i++)
	 	{
	 		if(s[i]==h[i])
	 		{
	 			auto k=fi[s[i]-97].begin();
	 			auto r=se[h[i]-97].begin();
	 			fi[s[i]-97].erase(k);
	 			se[h[i]-97].erase(r);
			}
			else
			{
				if(fi[s[i]-97].size()>=2)
				{
					auto k=fi[s[i]-97].begin();
				    fi[s[i]-97].erase(k);
				    ll d=*(fi[s[i]-97].begin());
				    p.pb(mp(d + 1,i+1));
				    auto r=se[h[i]-97].begin();
				    se[h[i]-97].erase(r);
				    fi[h[i]-97].insert(d);
				    s[d]=h[i];
				    k=fi[s[i]-97].begin();
				    fi[s[i]-97].erase(k); 
				}
				else
				{
					auto r=se[s[i]-97].begin();
					ll u=*r;
					p.pb(mp(u+1,u+1));
					fi[h[u]-97].insert(u);
					se[s[u]-97].insert(u);
					se[h[u]-97].erase(r);
					auto k=fi[s[u]-97].find(u);
					fi[s[u]-97].erase(k);
					swap(s[u],h[u]);
					//******************
					k=fi[s[i]-97].begin();
				    fi[s[i]-97].erase(k);
				    ll d=*(fi[s[i]-97].begin());
				    p.pb(mp(d + 1,i+1));
				    r=se[h[i]-97].begin();
				    se[h[i]-97].erase(r);
				    fi[h[i]-97].insert(d);
				    s[d]=h[i];
				    k=fi[s[i]-97].begin();
				    fi[s[i]-97].erase(k); 	
				}
			}
		}
		cout<<p.size()<<endl;
		for(ll i=0;i<p.size();i++)
		{
			cout<<p[i].ff<<" "<<p[i].ss<<endl;
		}
	 	
	 }
	 
    
}
}
