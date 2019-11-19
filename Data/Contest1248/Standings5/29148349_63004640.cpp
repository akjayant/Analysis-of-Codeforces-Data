#include<bits/stdc++.h>
using namespace std;
#define T int t; cin>>t; while(t--)
#define ll long long int
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define pb push_back
#define mp make_pair
// ed is gcd
ll ed, ex, ey;
void extendedEuclid(ll A,ll B)
{
    if(B==0) 
    {
        ed=A;
        ex=1;
        ey=0;
    }
    else 
    {
        extendedEuclid(B, A%B);
        ll temp=ex;
        ex=ey;
        ey=temp-(A/B)*ey;
    }
}
ll modInverse(ll A,ll M)
{
    extendedEuclid(A,M);
    return (ex%M+M)%M;
}
ll todec(ll b,string s)
{
    ll ans=0,c=1,l=s.length();
    reverse(s.begin(), s.end());
    for(ll i=0;i<l;i++)
    {
        if(s[i]<='9')
        ans+=c*(s[i]-'0');
        else
        ans+=c*(s[i]-'A'+10);
        c=c*b;
    }
    return ans;
}
ll power(ll x,ll y) 
{ 
    ll res = 1;
    x=x%mod;  
    while(y>0) 
    { 
        if (y & 1) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;   
    } 
    return res; 
}
ll arr[100005];
int main()
{
	//code
	fastio
	ll n,m;
	cin>>n>>m;
	if(m>n)
	{
	    m=m^n;
	    n=m^n;
	    m=m^n;
	}
	arr[0]=0;
	arr[1]=2;
	arr[2]=4;
	for(ll i=3;i<=n;i++)
	arr[i]=((arr[i-1]%mod)+(arr[i-2]%mod))%mod;
	ll ans=(arr[m]%mod + arr[n]%mod - 2)%mod;
	cout<<ans;
	return 0;
}