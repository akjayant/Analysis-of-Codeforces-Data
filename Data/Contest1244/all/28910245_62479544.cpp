#include <bits/stdc++.h>
using namespace std;
#define re return
#define ll long long
#define du double
#define co continue
#define gcd __gcd
#define br break
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    fast();
    ll n,p,w,d;
    cin >> n >> p >> w >> d;
    //if (n>1000000000) re 1;
    ll l=-1;
    ll r=n;
    ll h;
    while(l+1<r){
        h=(l+r)/2;
        if (h*w>=p-((n-h)*d)) r=h;
        else l=h;
    }
    ll mn=r;
    //cout << mn << endl;
    for (ll i=mn;i<=mn+1000000;++i){
        if (i*w<=p){
            if ((p-(i*w))%d==0 && i+(p-(i*w))/d<=n){
                cout << i << " ";
                cout << (p-(i*w))/d << " ";
                cout << n-(i+(p-(i*w))/d) << " ";
                cout << endl;
                re 0;
            }
        }
    }
    cout << -1;
    re 0;
}
/*
1000000000
100000000000
969
1
*/
