#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define line cout<<"---------------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
int  main()
{
    ll n ;
    cin>>n;
    ll  ans=n;
    for(ll  i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans=__gcd(ans,i);
            ll  d=n/(i);
            if(d!=i) ans=__gcd(ans,d);
        }
    }
    cout<<ans<<endl;
}
