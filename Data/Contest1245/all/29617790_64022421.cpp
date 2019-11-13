/// ANTI_LIGHT

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define f first
#define s second

const int maxn=1e5+100;
const int mod=1e9+7;


main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int ans=__gcd(a,b);
        if(ans==1)
            cout<<"FINITE"<<endl;
        else
            cout<<"INFINITE"<<endl;
    }
    return 0;
}
