#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
#define ll  long long
#define vi  vector<ll >
#define vvi vector<vi >
#define all(x) x.begin(), x.end()

ll n, k;
string s, t;
vi u;

bool alternate() {
    if (n % 2) return false;
    char c = s[0];
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0 && s[i] != c) return false;
        if (i % 2 == 1 && s[i] == c) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    if (alternate()) {
        if (k % 2) {
            for (int i = 0; i < n; ++i)
                s[i] = 'W' + 'B' - s[i];
        }
        cout << s;
        return 0;
    }
    t = s + s + s;
    u.assign(3 * n, 0);
    int pos = 0;
    while (t[pos] != t[pos + 1])
        ++pos;
    for (int i = pos; i < pos + n; ++i) {
        if (t[i] == t[i + 1])
            u[i] = u[i + 1] = 1;
    }
    u[pos + n] = 1;
    for (int i = pos; i < pos + n; ++i) {
        if (u[i]) continue;
        int j = i;
        while (u[j + 1] == 0) ++j;
        int num = j - i + 1;
        if (num % 2 == 0) {
            char c;
            if (2 * k >= num) {
                c = 'W' + 'B' - t[i];
                for (int e = i; e < i + num / 2; ++e)
                    t[e] = c;
                c = 'W' + 'B' - t[j];
                for (int e = j; e > j - num / 2; --e)
                    t[e] = c;
            }
            else {
                c = 'W' + 'B' - t[i];
                for (int e = i; e < i + k; ++e)
                    t[e] = c;
                c = 'W' + 'B' - t[j];
                for (int e = j; e > j - k; --e)
                    t[e] = c;
                if (k % 2 == 1) {
                    for (int e = i + k; e <= j - k; ++e)
                        t[e] = 'W' + 'B' - t[e];
                }
            }
        }
        else {
            char c;
            if (2 * k >= num) {
                c = 'W' + 'B' - t[i];
                for (int e = i; e <= j; ++e)
                    t[e] = c;
            }
            else {
                c = 'W' + 'B' - t[i];
                for (int e = i; e < i + k; ++e)
                    t[e] = c;
                for (int e = j; e > j - k; --e)
                    t[e] = c;
                if (k % 2 == 1) {
                    for (int e = i + k; e <= j - k; ++e)
                        t[e] = 'W' + 'B' - t[e];
                }
            }
        }
        i = j;
    }
    if (pos == 0)
        cout << t.substr(0, n);
    else
        cout << t.substr(n, pos) + t.substr(pos, n - pos);

    return 0;
}