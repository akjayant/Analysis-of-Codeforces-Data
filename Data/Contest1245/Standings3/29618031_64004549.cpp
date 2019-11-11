#include <bits/stdc++.h>
#define N 1000005
#define ll long long int 	
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define sp " "
#define endl "\n"
#define fi first
#define se second
#define ii pair<int,int>
#define lli pair<ll,ll>
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define fast2 freopen ("badhair.gir","r",stdin);freopen ("badhair.cik","w",stdout);
#define mod 1000000007
#define fs(x,y) for(ll i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(ll i=x;i<=y;i++)
#define INF 1000000000005
using namespace std;

ll n,m,ar[N],sum,t;

char s[N];

int main()
{
	fast;
	// cout<<endl;
	cin>>t;
	while(t--)
	{
		int a,b,c,x=0,y=0,z=0;
		int d,e,f;
		// n=a+b+c;
		cin>>n;
		cin>>a>>b>>c;
		cin>>s+1;
		fo(i,1,n)
		{
			if(s[i]=='R')
				x++;
			if(s[i]=='P')
				y++;
			if(s[i]=='S')
				z++;
		}
		ll k=min(a,z)+min(b,x)+min(c,y);
		d=a-min(a,z);
		e=b-min(b,x);
		f=c-min(c,y);
		// cout<<k<<endl;
		if(k<(n+1)/2)
		{
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		// cout<<a<<sp<<b<<sp<<c<<sp<<sp<<x<<sp<<y<<sp<<z<<endl;
		fo(i,1,n)
		{
			if(s[i]=='R')
			{
				if(b)
				{
					b--;
					s[i]='P';
				}
				else
				{
					if(d)
					{
						d--;
						s[i]='R';
						continue;
					}
					if(e)
					{
						e--;
						s[i]='P';	
						continue;
					}
					if(f)
					{
						f--;
						s[i]='S';
						continue;
					}

				}
				continue;
			}
			if(s[i]=='P')
			{
				if(c)
				{
					c--;
					s[i]='S';
				}
				else
				{
					if(d)
					{
						d--;
						s[i]='R';
						continue;
					}
					if(e)
					{
						e--;
						s[i]='P';	
						continue;
					}
					if(f)
					{
						f--;
						s[i]='S';
						continue;
					}

				}
				continue;
			}
			if(s[i]=='S')
			{
				if(a)
				{
					a--;
					s[i]='R';
				}
				else
				{
					if(d)
					{
						d--;
						s[i]='R';
						continue;
					}
					if(e)
					{
						e--;
						s[i]='P';	
						continue;
					}
					if(f)
					{
						f--;
						s[i]='S';
						continue;
					}

				}
			}
			continue;
		}

		cout<<s+1<<endl;
	}

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/