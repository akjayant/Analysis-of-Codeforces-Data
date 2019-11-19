#include <bits/stdc++.h>

using namespace std;

long long n, q, f, f1, f2, f3, f4, cnt, cnt1;
long long p, a, b, p1, ost[200000];

int main() {
    cin >> n >> p >> a >> b;

    if (p == 0) {
        cout << 0 << " " << 0 << " " << n;
        return 0;
    }
    if (p % a == 0) {
        if (p / a > n) {
            cout << -1;
            return 0;
        } else {
            cout << p / a << " " << 0 << " " << n - p / a;
            return 0;
        }
    }

    p1 = p;
    while (p1 >= 0) {
        if (ost[p1 % b] != 0) {
            break;
        }
        cnt++;
        ost[p1 % b] = cnt;
        p1 -= a;
    }
    if (ost[0] == 0) {
        cout << -1;
        return 0;
    }
    long long val1 = ost[0] - 1;
    long long val2 = (p - val1 * a) / b;
    long long val3 = n - val1 - val2;
    if (val3 >= 0) {
        cout << val1 << " " << val2 << " " << val3;
        return 0;
    }
    long long newVal = p - val1 * a;
    long long nok = a * b / __gcd(a, b);
    newVal %= nok;
    val2 = newVal / b;
    val1 = (p - newVal) / a;
    val3 = n - val1 - val2;
    if (val3 < 0) {
        cout << -1;
        return 0;
    }
    cout << val1 << " " << val2 << " " << val3;




}
