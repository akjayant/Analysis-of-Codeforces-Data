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
    ll n,m;
    cin >> n >> m;
    ll o=0,no=1;
    ll ans=0;
    ll a,b;
    if (n==1 && m==1){
        cout << 2;
        re 0;
    }
    for (int i=2;i<=n;++i){
        a=o;
        b=no;
        no+=a;
        o=b;
        o%=mod;
        no%=mod;
    }
    //cout << o << " " << no << endl;
    ans+=(o+no)*2;
    ans%=mod;
    o=0;
    no=1;
    for (int i=2;i<=m;++i){
        a=o;
        b=no;
        no+=a;
        o=b;
        o%=mod;
        no%=mod;
    }
    ans+=(o+no)*2;
    ans-=2;
    if (ans<0) ans+=mod;
    ans%=mod;
    cout << ans;
    re 0;
}
