//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second
#define y1 bbp
#define sz size()
using namespace std;
ll const N=1e6+7,inf=1e9+7;
ll a[N],b[N],qq,m,n,k,x,y,r,ans,q;
string s,t;
pair <ll,ll> p[N];
vector <ll> ot,v;
ll us[N];
char ch;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    m=n;
    if (n==1) return cout<<1,0;
    for (ll i=2;i*i<=n;i++)
    {
        if (n%i==0) ot.pb(i);
        while(n%i==0)
        {
            n/=i;
        }
    }
    if (n>1) ot.pb(n);
    if (ot.sz==1) cout<<ot[0]; else cout<<1;
}

