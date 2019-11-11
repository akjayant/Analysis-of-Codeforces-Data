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
const ll fu=(((ll)1)<<20)+5;

class Solution
{
	public:
	void SolutionFunc()
	{
		string s;
		cin>>s;
		ll n=s.length();
		ll ucount=0;
		ll ncount=0;
		vll dp(n);
		dp[0]=1;
		dp[1]=2;
		ll ans=1;
		rep(i,2,n)
		{
			dp[i]=(dp[i-2]+dp[i-1])%MOD;
		}
		forz(i,n)
		{
			if( (s[i]=='m') || (s[i]=='w') )
			{
				cout<<0<<endl;
				return;
			}
			if((s[i]!='n')&&(ncount>0))
			{
				ans*=dp[ncount-1];
				ans%=MOD;
				ncount=0;
			}
			if((s[i]!='u')&&(ucount>0))
			{
				ans*=dp[ucount-1];
				ans%=MOD;
				ucount=0;
			}
			if(s[i]=='n')
			{
				ncount++;
				ucount=0;
			}
			if(s[i]=='u')
			{
				ucount++;
				ncount=0;
			}
		}
		if(ncount>0)
			ans*=dp[ncount-1];
		if(ucount>0)
			ans*=dp[ucount-1];
		ans%=MOD;
		cout<<ans<<endl;
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