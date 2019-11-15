#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    size_t n = s.length();

    for (char c : s) {
        if (c == 'm' || c == 'w') {
            cout << 0 << '\n';
            return 0;
        }
    }

    int64_t modulo = 1000000007;
    int64_t p = 1;
    int64_t pp = 1;

    for (size_t i = 1; i < n; ++i) {
        int64_t next = p;
        if (s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u')) {
            next += pp;
        }
        pp = p;
        p = next;
        p %= modulo;
        pp %= modulo;
    }

    cout << p << '\n';
}
