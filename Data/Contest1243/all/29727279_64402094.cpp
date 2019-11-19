#include<bits/stdc++.h>
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i,ans=0;
        cin>>n;
        ll f=1;
        for(i=2;i*i<=n;i++)
        {
            if(n%i == 0)
            {
                f=0;
                ans=__gcd(ans,i);
                if(n/i != i)
                    ans=__gcd(ans,n/i);
            }
        }
        if(f)
            cout<<n<<"\n";
        else cout<<ans<<"\n";
    }
    return 0;
}