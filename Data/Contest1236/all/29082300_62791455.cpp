#include <bits/stdc++.h>
#define intt long long
#define pb push_back
#define mk make_pair
#define ii pair<int,int>
#define sc second
#define fr first
using namespace std;
intt mod=1e9+7;
intt power(intt x,  intt y, intt p)
{
    intt res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1ll; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int main()
{
   intt n,m;
   cin>>n>>m;
     intt f1=power(2,m,mod);
     f1--;
     f1+=mod;
     f1%=mod;
     intt ans=power(f1,n,mod);
     cout<<ans;
    return 0;
}
