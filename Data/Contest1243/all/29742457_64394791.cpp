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
    ll n;
    cin >> n;
    if (n==1){
        cout << 1;
        re 0;
    }
    ll f=0;
    for (int i=2;i<=1000000;++i){
        while (n%i==0){
            f++;
            n/=i;
        }
        if (f){
            if (n!=1){
                cout << 1;
                re 0;
            }
            else{
                cout << i;
                re 0;
            }
        }
    }
    cout << n;
    re 0;
}
