#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n,p,w,d;
    cin >> n >> p >> w >> d;
    ll ans = p/w;
    for(ll i=ans,j=0;i>=0&&j<=100000;i--,j++)
    {
        ll q = p-i*w;
        if(q%d==0)
        {
            q = q/d;
            ll c = n-i-q;
            if(c>=0)
            cout << i << " " << q << " " << c << "\n", exit(0);
        }
    }
    cout << -1 << endl;
    return 0;
}
