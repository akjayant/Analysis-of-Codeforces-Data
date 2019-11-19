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
    cin>>test;
    while(test--){
        ll l, p, a, b, k;
        cin>>l>>p>>a>>b>>k;
        ll ans=(l-1)/a;
        ans++;
        ll tm = k-ans;
        if(tm*b >=p )cout<<ans<<" "<<tm<<endl;
        else cout<<-1<<endl;


    }


    return 0;
}
