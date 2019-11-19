#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 1000005
#define mod 1000000007
using namespace std;
int main()
{
    IOS
    ll test;
        ll g, p, w, d;
        cin>>g>>p>>w>>d;
        ll ans=(p%w);
        ll drw=0, wn=0;
        for(ll i=0; i<=w && i<=g; i++){
            if( (i*d)%w==ans ){drw=i; break; }
            if(i==w){cout<<-1; return 0; }
        }
        wn=(p - (drw*d))/w;
        ll ls=(g-wn-drw);
        if(wn*w+drw*d==p && wn>=0 && drw>=0 && ls>=0)cout<<wn<<" "<<drw<<" "<<ls;
        else cout<<-1;





    return 0;
}
