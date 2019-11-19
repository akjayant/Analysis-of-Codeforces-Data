#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iterator>

#define mod 1000000007

using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    
    long long n;
    cin >> n;
    long long m;
    cin >> m;
    n--;
    m--;
    long long max_n = max(m, n)+5;
    vector<long long> fib(max_n+5);
    fib[0] = 2;
    fib[1] = 4;
    for (long long j = 2; j<=max_n; j++) {
        fib[j] = (fib[j-1]+fib[j-2])%mod;
    }
    long long ans = (fib[m]+fib[n]-2)%mod;
    cout << ans;

    return 0;
}