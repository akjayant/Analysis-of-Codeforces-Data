#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 100;

int f1(vector<int>& a, int d) {
    int l = -1, r = (int)a.size() - 1, m;
    if (a.empty() || a[r] < d) return -1;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (a[m] >= d) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return a[r];
}

int f2(vector<int>& a, int d) {
    int l = 0, r = (int)a.size(), m;
    if (a.empty() || a[l] > d) return -1;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (a[m] <= d) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return a[l];
}

int main() {
    vector<int> a[N], b[N];
    long long n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> y >> x;
        a[y - 1].push_back(x - 1);
        b[x - 1].push_back(y - 1);
    }

    for (int i = 0; i < max(n, m); ++i) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
    }

    long long c = 1;
    int x = 0, y = 0, now, mem_y, mem_x;
    int down = n - 1, up = 0, left = 0, right = m - 1;
    while (true) {
        mem_y = y;
        mem_x = x;
        now = f1(a[y], x);
        if (now != -1 && now <= right) {
            right = now - 1;
        }
        if (right < left)
            break;
        //cout << left << ' ' << right << ' ' << up << ' ' << down << " | " << y << ' ' << x << ' ' << now << ' ' << c << '\n';
        c += right - x;
        up += 1;
        x = right;
        //cout << left << ' ' << right << ' ' << up << ' ' << down << " | " << y << ' ' << x << ' ' << now << ' ' << c << "\n\n";

        now = f1(b[x], y);
        if (now != -1 && now <= down) {
            down = now - 1;
        }
        if (down < up)
            break;
        //cout << left << ' ' << right << ' ' << up << ' ' << down << " | " << y << ' ' << x << ' ' << now << ' ' << c << "\n";
        c += down - y;
        right -= 1;
        y = down;
        //cout << left << ' ' << right << ' ' << up << ' ' << down << " | " << y << ' ' << x << ' ' << now << ' ' << c << "\n\n";

        now = f2(a[y], x);
        if (now != -1 && now >= left) {
            left = now + 1;
        }
        if (right < left)
            break;
        //cout << left << ' ' << right << ' ' << up << ' ' << down << " | " << y << ' ' << x << ' ' << now << ' ' << c << "\n";
        c += x - left;
        down -= 1;
        x = left;
        //cout << left << ' ' << right << ' ' << up << ' ' << down << " | " << y << ' ' << x << ' ' << now << ' ' << c << "\n\n";

        now = f2(b[x], y);
        if (now != -1 && now >= up) {
            up = now + 1;
        }
        if (down < up)
            break;
        //cout << left << ' ' << right << ' ' << up << ' ' << down << " | " << y << ' ' << x << ' ' << now << ' ' << c << "\n";
        c += y - up;
        left += 1;
        y = up;
        //cout << left << ' ' << right << ' ' << up << ' ' << down << " | " << y << ' ' << x << ' ' << now << ' ' << c << "\n\n";
        //cout << "----------------\n";
        if (y == mem_y && x == mem_x)
            break;
    }

    if (c != n * m - k) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}
