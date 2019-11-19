# include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;

long long n, p, w, d, x, y;
int us[N];

int main() {
    cin >> n >> p >> w >> d;

    x = p / w;

    long long cur = p % w;

    while (!us[cur % d]) {
        if (cur % d == 0) {
            if (x + cur / d <= n && x >= 0) {
                cout << x << " " << cur / d << " " << n - x - cur / d << endl;
                return 0;
            }
        }
        us[cur % d] = 1;
        cur += w;
        x --;
    }

    cout << -1 << endl;
}
