#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
const ll MOD = 1e9+7;

int main(){
    fastio;
    int a,b,t;
    cin>>t;
    while(t--){
        cin >> a >> b;
        int c = __gcd(a,b);
        if(c == 1){
            cout << "Finite\n";
        }
        else{
            cout << "Infinite\n";
        }
    }
    return 0;
}