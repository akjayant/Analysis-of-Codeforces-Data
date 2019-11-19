#include<bits/stdc++.h>
#define M 100001
#define MAX 1000000000000000
#define mod 1000000007
#define ss second
#define ff first
#define ll long long int
#define pb push_back
#define ld double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll gcd(ll a,ll b)
{
    if(a < b)
        swap(a,b);
    if(a == 0|| b==0)
        return (a+b);
    return gcd(b,a%b);
}

int main()
{
    ll n,ans=-1,g=0;
    cin>>n;
    for(ll i = 2;i*i <= n;i++)
    {
        if(n%i == 0){
            g = gcd(g,i);
            g=gcd(g,n/i);
        }
    }
    if(g == 0)
        g = n;
    cout<<g<<endl;

    return 0;
}