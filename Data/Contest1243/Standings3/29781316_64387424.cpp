#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1006;
ll n, i, cmmdc;
int main()
{
    cin>>n;
    cmmdc=n;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
            cmmdc=__gcd(cmmdc,__gcd(i,n/i));
    cout<<cmmdc;
    return 0;
}
