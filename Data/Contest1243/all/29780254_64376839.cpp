#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

vector<int> arr;

int main() {
    long long x; cin >> x;

    long long y = x;
    for (long long i = 2; i*i <= x; i++) {
        if (x%i == 0) {
            y = i;
            break;
        }
    }

    while (x > 1 && (x%y) == 0) x /= y;
    if (x != 1) cout << 1 << endl;
    else cout << y << endl;
}
