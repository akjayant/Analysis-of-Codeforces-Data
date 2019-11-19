#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back 
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define ld long double
#define int long long int 
#define F first 
#define S second
signed main()
{
    fast;
    int n;
    cin>>n;
    vector<int> fact;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            fact.pb(i);
            int x = n/i;
            if(x!=i)
            {
                fact.pb(x);
            }
        }
    }
    if(fact.size()==0)
    {
        cout<<n;
    }
    else
    {
        int ans = fact[0];
        int sz = fact.size();
        for(int i=1;i<sz;i++)
        {
            ans = __gcd(ans,fact[i]);
        }
        cout<<ans;
    }
}