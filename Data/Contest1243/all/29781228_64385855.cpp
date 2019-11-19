#include <iostream>
#define int long long
using namespace std;

int gcd(int a, int b) {
    if (b != 0)
        return gcd(b, a % b);
    return a;
}

signed main() {
    int n;
    cin >> n;
    int g = n;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0)
            g = gcd(gcd(g, i), n / i);
        i++;
    }
    cout << g << endl;
    return 0;
}
