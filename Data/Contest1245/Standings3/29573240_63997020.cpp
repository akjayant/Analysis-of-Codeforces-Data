#include <iostream>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int main() {
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        int64_t a, b;
        cin >> a >> b;
        if (GCD(a, b) == 1) {
            cout << "Finite\n";
        } else {
            cout << "Infinite\n";
        }
    }
}
