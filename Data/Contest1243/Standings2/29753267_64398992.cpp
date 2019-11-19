#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N=2e5+5;
int cnt[30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll j=2;
    int cnt=0;
    ll ans=1;
    while(j*j<=n)
    {
        if(n%j==0)
        {
            ans=j;
            cnt++;
            while(n%j==0)
                n/=j;
        }
        j++;
    }
    if(n!=1) cnt++,ans=n;
    if(cnt>1) cout<<1<<endl;
    else cout<<ans<<endl;
    return 0;
}
