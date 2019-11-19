#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

int32_t main() {
    int n;
    cin >> n;
    if(isPrime(n)) {
        cout << n << '\n';
    } else {
        int ans = 1;
        for(int i = 2; i < n; ++i) {
            if(n % i == 0) {
                while(n % i == 0) {
                    n = n / i;
                }
                ans = i;
                break;
            }
        }
        if(n > 1) {
            ans = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}