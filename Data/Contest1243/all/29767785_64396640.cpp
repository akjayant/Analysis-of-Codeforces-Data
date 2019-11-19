#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    
    cin >> n;
    long long a = 1;
    for (long long i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            a = i;
            break;
        }
    }
    
    if (a == 1) cout << n << endl;
    else {
        while (n % a == 0) n /= a;
        if (n == 1) cout << a << endl;
        else cout << 1 << endl;
    }
}
