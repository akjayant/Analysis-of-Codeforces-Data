#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

long long gcd(long long big, long long small) {
    if (big % small == 0) return small;
    else return gcd (small, big % small);
}

int main(int argc, const char * argv[]) {
    int k, n;
    cin >> k;
    string s, t;
    char a, b;
    for (int j = 0; j < k; ++j) {
        cin >> n;
        cin >> s >> t;
        int i = 0;
        while (s[i] == t[i]) ++i;
        a = s[i];
        b = t[i];
        ++i;
        bool can = true;
        while (i < n - 1 && s[i] == t[i]) ++i;
        if (i == n - 1 && s[i] == t[i]) {
            can = false;
        }
        if (s[i] != a || t[i] != b) {
            can = false;
        }
        ++i;
        for (; i < n; ++i) {
            if (s[i] != t[i]) {
                can = false;
            }
        }
        if (can) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
