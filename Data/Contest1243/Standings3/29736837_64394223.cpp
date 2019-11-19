#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    set<int> primes;
    // cout<<n<<'\n';
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            // cout<<i<<'\n';
            primes.insert(i);
            while(n%i==0)
            {
                // cout<<n<<'\n';
                // cout<<n<<' '<<i<<'\n';
                n=n/i;
            }
        }
    }
    if(n!=1)
    {
        primes.insert(n);
    }
    if(primes.size()==1)
    {
        cout<<*primes.begin();
    }
    else
    {
        cout<<1;
    }
}