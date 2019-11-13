#include <bits/stdc++.h>
#define loop(i, a, b) for(long long  i=a;i<b;i++)
#define mn 500100
#define mod 1000000007
 
using namespace std;
 
typedef long long ll;

ll euc(ll a, ll b){
    if(a%b==0) return b;
    return euc(b, a%b);
}

int main() {
    ll t; cin >> t;
    loop(afskifn, 0, t){
        ll a, b;cin >> a>>b;
        if(euc(a, b)==1)cout << "Finite"<<endl;
        else cout << "Infinite"<<endl;
    }
}