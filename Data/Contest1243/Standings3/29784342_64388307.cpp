#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

long long gcd(long long big, long long small) {
    if (big % small == 0) return small;
    else return gcd (small, big % small);
}

int main(int argc, const char * argv[]) {
    long long n, k;
    cin >> n;
    k = n;
    set<long long>del;
    for (long long i = 2; del.size() < 3 && i * i <= n; ++i) {
        if (n % i == 0) {
            del.insert(i);
        }
        while (n % i == 0) n /= i;
    }
    if (n > 1 && n != k) del.insert(n);
    if (del.size() == 0) cout << n << endl;
    else if (del.size() == 1) cout << *del.begin() << endl;
    else cout << 1 << endl;
    return 0;
}
