#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int main()
{
    //freopen("test.in","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,in; cin>>n;
    in=n;
    vector<int> pr;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0) pr.pb(i);
        while(n%i==0) n/=i;
    }
    if(n!=1 && in!=n) pr.pb(n);
    if(pr.size()==0) cout<<n<<'\n';
    else if(pr.size()==1) cout<<pr[0]<<'\n';
    else cout<<1<<'\n';
    return 0;
}
