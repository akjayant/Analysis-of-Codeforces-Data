#include <bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
using namespace std;
long long poww(long long a,long long b,long long p)
{
    long long result=1;
    for(;b;)
    {
        if(b&1)
        {
            result=result*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return result;
}
ll n,m;
int main() {
    cin >> n >> m;
    ll result=poww(2,m,mod)-1;
    ll result2=poww(result,n,mod);
    cout << (result2+mod)%mod << endl;
    return 0;
}