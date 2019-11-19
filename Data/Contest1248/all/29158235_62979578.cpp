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
int p[N + 1];
int q[N + 1];
int cnt1[2], cnt2[2];
main() {
    int t = readInt();
    while (t--) {
        int n = readInt();
        cnt1[0] = cnt2[0] = cnt1[1] = cnt2[1] = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = readInt();
            cnt1[p[i] % 2]++;
        }
        int m = readInt();
        for (int i = 1; i <= m; i++) {
            q[i] = readInt();
            cnt2[q[i] % 2]++;
        }
        cout << cnt1[0] * cnt2[0] + cnt1[1] * cnt2[1] << "\n";
    }
}
