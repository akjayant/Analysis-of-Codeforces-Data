/*
Author: Arjan Singh Bal, IIITM Gwalior
"Everything in this world is magic, except to the magician"
*/

#include                        <bits/stdc++.h>
#ifdef LOCAL
#include                        "pprint.hpp"
#endif

using namespace std;

#define prn(...) __f(__VA_ARGS__)
template <typename Arg1>
void __f(Arg1&& arg1)
{
    cout<<arg1<<"\n";
}
template <typename Arg1, typename... Args>
void __f(Arg1&& arg1, Args&&... args)
{
    cout<<arg1<<" "; __f(args...);
}

#define read(...) __g(__VA_ARGS__)
template <typename Arg1>
void __g(Arg1&& arg1)
{
    cin>>arg1 ;
}
template <typename Arg1, typename... Args>
void __g(Arg1&& arg1, Args&&... args)
{
    cin>>arg1; __g(args...);
}

#define ll                      long long
#define pii                     pair<int, int>
#define pli                     pair<ll, int>
#define pil                     pair<int, ll>
#define pll                     pair<ll, ll>
#define pdd                     pair<double, double>
#define vi                      vector<int>
#define vc                      vector<char>
#define vll                     vector<ll>
#define vb                      vector<bool>
#define vd                      vector<double>
#define vs                      vector<string>
#define ff                      first
#define ss                      second
#define pb                      push_back
#define eb                      emplace_back
#define ppb                     pop_back
#define pf                      push_front
#define ppf                     pop_front
#define vpii                    vector<pii>
#define umap                    unordered_map
#define all(x)                  x.begin(),x.end()
#define clr(a,b)                memset(a,b,sizeof a)
#define fr(i,n)                 for(int i=0; i<n;++i)
#define fr1(i,n)                for(int i=1; i<=n; ++i)
#define precise(x)              cout<<fixed<<setprecision(x)

ll n, p, w, d;

ll gex(ll a, ll b, ll &x, ll &y)
{
	if(!a){
		x=0;
		y=1;
		return b;
	}

	ll x1, y1;
	ll g=gex(b%a, a, x1, y1);
	x=y1-(b/a)*x1;
	y=x1;
	return g;
}

ll inv(ll a, ll m)
{
	ll x, y;
	ll g=gex(a, m, x, y);
	assert(g==1);
	return (x%m+m)%m;
}

int main()
{
	//freopen("in.txt" , "r" , stdin) ;
	//freopen("out.txt" , "w" , stdout) ;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	read(n, p, w, d);

	ll g=__gcd(w, d);
	if(p%g){
		prn(-1);
		return 0;
	}

	p/=g;
	w/=g;
	d/=g;

	ll x, y;

	x=(p%d)*inv(w, d)%d;
	y=(p-x*w)/d;

	if(y>=0 && x+y<=n){
		prn(x, y, n-x-y);
		return 0;
	}



	y=(p%w)*inv(d, w)%w;

	x=(p-y*d)/w;

	if(x>=0 && x+y<=n){
		prn(x, y, n-x-y);
		return 0;
	}

	

	prn(-1);

	return 0;
}