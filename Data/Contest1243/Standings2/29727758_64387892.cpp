#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPrime(ll x){
    for (ll i=2; i*i<=x; i++){
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    if (isPrime(n)) cout << n << endl;
    else{
        ll temp = n;
        for (ll i=2; i*i<=n; i++){
            if (temp % i == 0){
                while(temp % i == 0) temp /= i;
                if (temp > 1) cout << 1 << endl;
                else{
                    cout << i << endl;
                }
                return 0;
            }
        }
    }


}