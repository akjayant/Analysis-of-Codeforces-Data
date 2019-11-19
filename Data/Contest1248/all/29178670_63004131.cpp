#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll M = pow(10,9) + 7;
vector<ll> fib(100005,1);
void init()
{
    for(int i=2;i<fib.size();i++)
    {
        fib[i] = (fib[i-1]%M + fib[i-2]%M)%M;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    init();
    ll ans = (2*(fib[m] + fib[n] - 1)%M)%M;
    ans%=M;
    cout<<ans<<endl;
    return 0;
}