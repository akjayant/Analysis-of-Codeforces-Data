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
    ll n,m,t,a,b,k1,k2,k3,k4;
    cin >> t;
    while (t--){
        k1=0;
        k2=0;
        k3=0;
        k4=0;
        cin >> n;
        for (int i=1;i<=n;++i){
            cin >> a;
            if (a%2) k1++;
            else k2++;
        }
        cin >> m;
        for (int i=1;i<=m;++i){
            cin >> b;
            if (b%2) k3++;
            else k4++;
        }
        cout << k3*k1+k2*k4 << "\n";
    }
    re 0;
}
