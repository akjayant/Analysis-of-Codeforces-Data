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
const ll mod=1000000007;
int main()
{
    fast();
    ll n;
    cin >> n;
    ll a[n+10];
    for (int i=1;i<=n;++i) cin >> a[i];
    ll x=0,y=0;
    sort(a+1,a+n+1);
    for (int i=1;i<=n/2;++i){
        x+=a[i];
    }
    for (int i=n/2+1;i<=n;++i){
        y+=a[i];
    }
    cout << x*x+y*y;
    re 0;
}
