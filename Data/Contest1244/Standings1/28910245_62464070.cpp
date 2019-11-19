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
    ll q,a,b,c,d,k,r,ka;
    cin >> q;
    while(q--){
        cin >> a >> b >> c >> d >> k;
        r=(a-1)/c+1;
        ka=(b-1)/d+1;
        if (r+ka<=k){
            cout << r << " " << ka << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
    re 0;
}
