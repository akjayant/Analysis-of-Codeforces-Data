#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;
const LL MOD=1e9+7;

const int MAX=100000009;

LL powe(LL n,LL k)
{
    if(k==0)
        return n%MOD;
    if(k==1)
        return n%MOD;
    LL temp=powe(n,k/2)%MOD;
    temp=(temp*temp)%MOD;
    if(k%2==0)
        return temp;
    return (temp*n)%MOD;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n,m;
    cin>>n>>m;
    cout<<powe((powe(2,m)+MOD-1)%MOD,n)%MOD;


}
