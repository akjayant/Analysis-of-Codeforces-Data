#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int mod = 1000000007;

int main() {
    string s;
    cin >> s;
    vector<int> d(s.length(), 0);
    d[0] = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return 0;
        }
        if (i == 0)
            continue;
        d[i] = d[i - 1];
        if ((s[i] == 'u' && s[i - 1] == 'u') || (s[i] == 'n' && s[i - 1] == 'n')) {
            if (i == 1)
                d[i] += 1;
            else
                d[i] += d[i - 2];
            d[i] %= mod;
        }
    }
    cout << d[s.length() - 1];
}