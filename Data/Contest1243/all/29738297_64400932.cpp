#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define f(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
#define vll vector<vector<long long>>
using namespace std;

ll gcd(ll x, ll y)
{
    if(x==0) return y;
    return gcd(y%x, x);
}

ll gcdArr(vl v)
{
    ll n = v.size();
    ll result = v[0];
    f(i, 1, n) result = gcd(v[i], result);
    return result;
}

vl div(ll n)
{
	vl v;
	for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0 && i != 1)
        {
            if (i*i == n) v.pb(i);
            else { v.pb(i); v.pb(n/i); }
        }
    }
    return v;
}

int main()
{
    IOS
    ll n, nv;
    cin>>n;
    vl v = div(n);
    nv = v.size();
    if(nv == 0) cout<<n;
    else cout<<gcdArr(v);
    return 0;
}