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
    ll k,n,v;
    cin >> k;
    ll a[1000+10];
    while(k--){
        cin >> n;
        for (int i=1;i<=n;++i) a[i]=0;
        for (int i=1;i<=n;++i){ cin >> v; a[v]++;}
        //cout << "lol" << endl;
        for (int i=n-1;i>=1;--i){
            a[i]=a[i+1]+a[i];
        }
        for (int i=n;i>=1;--i){
            if (a[i]>=i){
                cout << i << "\n";
                br;
            }
        }
    }
    re 0;
}
