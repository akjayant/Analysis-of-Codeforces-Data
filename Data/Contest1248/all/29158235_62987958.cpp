#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5;

int readInt ()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
int a[N + 1];
main() {
    int n = readInt();
    for (int i = 1; i <= n; i++) {
        a[i] = readInt();
    }
    sort(a + 1, a + n + 1);
    int x = 0, y = 0;
    int l = 1, r = n;
    int q = 0;
    while (r > l) {
        x += a[l];
        y += a[r];
        l++;
        r--;
    }
    int ans = x * x + y * y;
    if (n & 1) {
        ans = max((y + a[l]) * (y + a[l]) + x * x, y * y + (x + a[l]) * (x + a[l]));
    }
    x = 0, y = 0;
    l = 1, r = n;
    while (r > l) {
        x += a[r];
        y += a[l];
        l++;
        r--;
    }
    if (n & 1) {
        ans = max(ans, max((y + a[l]) * (y + a[l]) + x * x, y * y + (x + a[l]) * (x + a[l])));
    }
    cout << ans;
}
