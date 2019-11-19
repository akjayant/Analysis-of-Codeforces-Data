#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
const ll N=2e3+5,inf=1e18;
ll sum[N],ary[N];
ll root(ll i)
{
	while(ary[i]!=i)
	{
		ary[i]=ary[ary[i]];
		i=ary[i];//**************************************
	}
	return i;
}

ll un(ll a,ll b)
{
	ll rA=root(a);
	ll rB=root(b);
	if(rA==rB)return 0;
	if(sum[rA]>sum[rB])
	{
		ary[rB]=rA;
		sum[rA]+=sum[rB];
	}
	else
	{
		ary[rA]=rB;
		sum[rB]+=sum[rA];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin >> n;
	ll x[n],y[n];
	lp(i,0,n)
	{
		ary[i]=i;
		sum[i]=0;
		cin >> x[i] >> y[i];
	}	    
	ll c[n],k[n];
	lp(i,0,n)
	{
		cin >> c[i];
	}
	lp(i,0,n)
	{
		cin >> k[i];
	}
	vector<pair<ll,pll> > v;
	lp(i,0,n)
	{
		lp(j,i+1,n)
		{
			ll d=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
			v.pb(mp(d,mp(i,j)));
		}
	}
	lp(i,0,n)
	{
		v.pb(mp(c[i],mp(i,(ll)-1)));
	}
	sort(all(v));
	ll mk[n];
	ll ans=0;
	vll cv;
	vpll pv;
	memset(mk,0,sizeof(mk));
	lp(i,0,v.size())
	{
		ll id1=v[i].ss.ff;
		ll id2=v[i].ss.ss;
		if(id2==-1)
		{
			if(mk[root(id1)]==0)
			{
				mk[id1]=1;
				mk[root(id1)]=1;
				cv.pb(id1);
				ans+=v[i].ff;
			}
		}
		else
		{
			ll r1=root(id1);
			ll r2=root(id2);
			if(r1==r2)
			{
				continue;
			}
			else if(mk[r1]==1&&mk[r2]==1)
			{
				continue;
			}
			else if(mk[r1]==1)
			{
				mk[r2]=1;
				un(r1,r2);
				pv.pb(mp(id1,id2));
				ans+=v[i].ff;
			}
			else if(mk[r2]==1)
			{
				mk[r1]=1;
				un(r1,r2);
				pv.pb(mp(id1,id2));
				ans+=v[i].ff;
			}
			else
			{
				un(r1,r2);
				pv.pb(mp(id1,id2));
				ans+=v[i].ff;
			}
		}

	}
	cout<<ans<<endl;
	cout<<cv.size()<<endl;
	lp(i,0,cv.size())
	{
		cout<<cv[i]+1<<" ";
	}
	cout<<endl;
	cout<<pv.size()<<endl;
	lp(i,0,pv.size())
	{
		cout<<pv[i].ff+1<<" "<<pv[i].ss+1<<endl;
	}
	return 0;
}