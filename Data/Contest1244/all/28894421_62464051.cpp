#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    ll a, b, c, d, k;
    cin>>a>>b>>c>>d>>k;
    ll x = a/c;
    if (a%c) x++;
    ll y = b/d;
    if (b%d) y++;
    if (x+y>k)
        cout<<-1;
    else
        cout<<x<<" "<<y;
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    while (t--)
        solve();


    return 0;
}
