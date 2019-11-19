#include <iostream>
#include <utility>
using namespace std;
long long n, p, d, w;
pair <long long, long long> fun() {
    long long x = p / w;
    long long left = p - (x * w);
    long long mod = (d - (left % d)) % d;
    long long K = -1;
    for (long long tod = 0; tod <= d; tod++) {
        //cout << left << " " << w << " " << tod << " " << d << " " << mod << "\n";
        if (((w * tod) % d) == mod) {
            K = tod;
            break;
        }
    }
    if (K == -1 || K > x)
        return {-1, -1};
    long long y = (left + w * K) / d;
    //cout << x - K << " " << y << " " << K << " " << mod << " " << left << "\n";
    if ((x - K + y) > n)
        return {-1, -1};
    if (w > d)
        return {x - K, y};
    else
        return {y, x - K};
}
int main() {
    cin >> n >> p >> w >> d;
    pair <long long, long long> p = fun();
    if (p.first == -1) {
        cout << "-1";
        return 0;
    }
    cout << p.first << " " << p.second << " " << n - p.first - p.second;
}
