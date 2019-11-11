#include <bits/stdc++.h>

#define ll long long
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll INF = 1e17;
const ll MN = 1000000;


int main() {
    fast
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll g = __gcd(a,b);
        if(g == 1){
            cout<<"Finite";
        }
        else{
            cout<<"Infinite";
        }
        cout<<'\n';
    }
}