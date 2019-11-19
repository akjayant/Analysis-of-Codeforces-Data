#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 123456;
 
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        ll v = (a + c - 1) / c + (b + d - 1) / d;
        if(v <= k)  cout << (a + c - 1) / c << " " << (b + d - 1) / d << "\n";
        else    cout << "-1\n"; 
    }
}