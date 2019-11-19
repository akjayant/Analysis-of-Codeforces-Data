#include<bits/stdc++.h>
 
using namespace std;

bool is_prime(long long x) {
    for(long long i = 2; i * i <= x; ++i)
        if(x % i == 0)
            return false;
    return true;
}

void solve() {
    long long n;
    cin >> n;

    long long prime = -1;
    for(long long i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            long long j = n / i;

            if(is_prime(i)) {
                if(prime != -1 && i != prime) {
                    cout << 1 << endl;
                    return;
                }
                prime = i;
            }
            if(is_prime(j)) {
                if(prime != -1 && j != prime) {
                    cout << 1 << endl;
                    return;
                }
                prime = j;
            }
        }
    }

    if(prime == -1)
        cout << n << endl;
    else
        cout << prime << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //int t;
    //cin >> t;
    //for(auto i = 0; i < t; ++i)
        solve();
}