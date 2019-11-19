#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{   
    int n;
    cin>>n;

    int gcd = n;
    for(int i=2;i<=n;i++)
    {
        if( i*i > n)
            break;
        if(n%i==0)
        {
            gcd = __gcd(gcd, i);
            gcd = __gcd(gcd, n/i);
        }
    }

    cout<<gcd<<endl;

    return 0;
}