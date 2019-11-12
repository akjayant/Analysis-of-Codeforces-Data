#include<bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fr(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define endl "\n"
#define fast std::ios_base::sync_with_stdio(false)
#define mod 1000000007
#define pi 3.14159265
lli power(lli x, lli y) 
{ 
    if (y == 0) 
        return 1; 
    lli p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
    return (y%2 == 0)? p : (x * p) % mod; 
} 
li gcd(li a,li b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    fast;
    lli n,m,i;
    cin>>n>>m;
    lli a=power(2,m);
    a=(a-1+mod)%mod;
    cout<<power(a,n);
    return 0;
}