#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int inf = 1e9 + 7;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long c = a;
        a = b;
        b = c % b;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    long long del = 2;
    long long answer = n;
    while (del * del <= n) {
        if (n % del == 0) {
            answer = gcd(answer, del);
            answer = gcd(answer, n / del);
        }
        ++del;
    }
    cout << answer << endl;
    return 0;
}