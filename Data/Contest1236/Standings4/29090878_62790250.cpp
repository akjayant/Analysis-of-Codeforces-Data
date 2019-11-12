#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(x) cerr << #x"=" << x << endl;
#define fout cout<<fixed<<setprecision(10)
typedef long long int ll;
const int mod = 1e9+7;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    	return (a.first - a.second) > (b.first - b.second);
}
ll power(ll x, ll y) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
} 
ll power_mod(ll b,ll e,ll m)
{
    ll a=1;
    while(e !=0 )
    {
        if((e&1) == 1) 
            a= (a*b)%m;
        b=(b*b)%m; e>>= 1;
    }
    return a%m;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n,m;cin>>n>>m;
	ll t1 = power_mod(2,m,mod)-1;
	if(t1<0) t1+=mod;
	ll fin = power_mod(t1,n,mod);
	cout<<fin<<endl;
	return 0;
}