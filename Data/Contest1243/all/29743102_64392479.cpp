#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ldb;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define V vector
#define pll pair<ll,ll>
#define endl "\n"
#define CLEAR(a) memset(a,-1,sizeof(a))
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)x.size())
#define rep0(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define ios_tie() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(nullptr)
#define trace1(a)             cout <<#a<<":"<<a<< endl;
#define trace2(a,b)           cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<< endl;
#define trace3(a,b,c)         cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<endl;
#define trace4(a,b,c,d)       cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<" | "<<#d<<":"<<d<<endl;
#define trace5(a,b,c,d,e)     cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<" | "<<#d<<":"<<d<<" | "<<#e<<":"<<e<<endl;

const ll inf = 1e18;
const ll mod = 987654319 ;
const ll maxn = 2e5+10;
const ldb PI = acos(-1);

void lol(ll s) {cerr<<"check........................................... "<<s<<endl;}
ll power(ll x,ll y) {ll res=1; x%=mod; while(y) {if(y&1) res=(res*x)%mod; y>>=1LL; x=(x*x)%mod; }return res;}
ll inv(ll x) {return power(x,mod-2);}//(1/x)%y = x^(y-2) % y;   // pow(x,y)%m = pow(x,y%(m-1))%m
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

V<ll> getpfs(ll n)  
{  
	V<ll> res;
    while(n%2==0)  
    {  
        res.pb(2); 
        n /= 2;  
    }  
    for(ll i=3;i*i<=n;i+=2)  
        while(n%i==0) 
        {  
            res.pb(i); 
            n /= i;  
        }  
    if(n>2)
        res.pb(n);
    sort(all(res));
    res.erase(unique(all(res)),res.end());
    return res;
}  
int main()
{
	ios_tie();
	ll n;
	cin>>n;
	V<ll> v = getpfs(n);
	// for(auto it:v)
	// 	cout<<it<<" ";
	// cout<<endl;
	if(sz(v)==1)
		cout<<v[0]<<endl;
	else
		cout<<"1\n";
	return 0;
}
