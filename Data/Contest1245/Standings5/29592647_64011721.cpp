#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, n;
string s;
const long long maxn = 1000000007;
vector<long long> fib;

int main() {
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0 << endl;
            return 0;
        }
    }
    fib.resize(n + 21);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < n + 20; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % maxn;
    }
    long long answer = 1;
    long long leng = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == 'n') {
                leng = 1;
            } else if (s[i] == 'u') {
                leng = 1;
            }
        } else {
            if (s[i] == s[i - 1]) {
                if (s[i] == 'n') {
                    leng++;
                } else if (s[i] == 'u') {
                    leng++;
                }
            } else {
                if (leng != 0) {
                    answer = (answer * fib[leng]) % maxn;
                    leng = 0;
                }
                if (s[i] == 'n') {
                    leng++;
                } else if (s[i] == 'u') {
                    leng++;
                }
            }
        }
    }
    if (leng != 0) {
        answer = (answer * fib[leng]) % maxn;
        leng = 0;
    }
    cout << answer;
    return 0;
}