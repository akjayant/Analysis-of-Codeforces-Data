#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef long double ldo;
#define forz(iter,n)	for(ll iter=0;iter<n;++iter)
#define rep(iter,s,e)	for(ll iter=s;iter<e;++iter)
#define urep(iter,s,e)	for(ll iter=s;iter>=e;--iter)
#define MOD				(ll)1000000007
#define pp				pair<ll,ll>
#define vii				vector<int>
#define vll				vector<ll>
#define vpp				vector<pp>
#define vss				vector<string>
#define take(A,n)		{forz(iter,n)cin>>A[iter];}
#define pb				push_back
#define pob				pop_back
#define eb				emplace_back
#define pf				push_front
#define pof				pop_front
#define mkp				make_pair
#define all(a)			a.begin(),a.end()
#define ff				first
#define ss				second
#define lcm(a,b)		(a*b)/__gcd(a,b)
#define bs(v,x)			binary_search(all(v),x)
#define ub(v,x)			upper_bound(all(v),x)
#define lb(v,x)			lower_bound(all(v),x)
#define zoom			ios_base::sync_with_stdio(false);cin.tie(NULL);
template <class C> void setmin(C &a,C b){if(a>b)a=b;}
template <class C> void setmax(C &a,C b){if(a<b)a=b;}
template <class C> void printv(vector<C> vec,string end=" "){for(auto const&iter:vec)cout<<iter<<end;if(end!="\n")cout<<endl;}
template <class C> void printv(set<C> setc,string end=" "){for(auto const&iter:setc)cout<<iter<<end;if(end!="\n")cout<<endl;}
template <class C> void print(C A[],ll n,string end=" "){forz(iter,n)cout<<A[iter]<<end;if(end!="\n")cout<<endl;}
//for(auto const&x:mp)

ll C;
vector<vll> G(2005,vll(2005,0));
vll P(2005);
vll J(2005,numeric_limits<ll>::max());
vector<bool> mstSet(2005,false);

ll find(vll J,vector<bool> mstSet)
{
	ll mi=numeric_limits<ll>::max(),min_index;
	forz(v,C)
	{
		if((!mstSet[v])&&(J[v]<mi))
			mi=J[v],min_index=v;
	}
	return min_index;
}
void construct()
{
	J[0]=0;
	P[0]=-1;
	forz(i,C)
	{
		int u = find(J, mstSet);
		mstSet[u]=true;
		forz(v,C)
			if((G[u][v])&&(!mstSet[v])&&(G[u][v]<J[v]))
				P[v]=u,J[v]=G[u][v];
	}
}

class Solution
{
	public:
	void SolutionFunc()
	{
		ll n;
		cin>>n;
		vpp xy(n);
		forz(i,n)
		{
			cin>>xy[i].ff>>xy[i].ss;
		}
		vll c(n);
		vll k(n);
		take(c,n);
		take(k,n);
		forz(i,n)
		{
			forz(j,n)
			{
				G[i][j]=(abs(xy[i].ff-xy[j].ff)+abs(xy[i].ss-xy[j].ss))*(k[i]+k[j]);
			}
		}
		forz(i,n)
		{
			G[n][i]=c[i];
			G[i][n]=c[i];
		}
		C=n+1;
		// forz(i,C)
		// {
		// 	forz(j,C)
		// 		cout<<G[i][j]<<' ';
		// 	cout<<endl;
		// }
		construct();
		vll pow;
		vpp ans;
		ll total=0;
		rep(i,1,C)
		{
			if(P[i]==n)
				pow.pb(i+1);
			else if(i==n)
				pow.pb(P[i]+1);
			else
			{
				ans.pb({P[i]+1,i+1});
			}
			total+=G[i][P[i]];
		}
		cout<<total<<endl;
		cout<<pow.size()<<endl;
		printv(pow);
		cout<<ans.size()<<endl;
		for(auto const&x:ans)
		{
			cout<<x.ff<<' '<<x.ss<<endl;
		}

	}
};
int main()
{
	zoom;
	Solution ob;
	ll t=1;
	// cin>>t;
	forz(t1,t)
	{
		// cout<<"Case #"<<t1+1<<": ";
		ob.SolutionFunc();
	}
	return 0;
}