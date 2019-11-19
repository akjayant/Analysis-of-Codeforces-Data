 #include <bits/stdc++.h>

#define clr(x, y) memset(x, y, sizeof x)
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8, pi = acos(-1.0);
const int maxS = 1e6 + 13;
const int maxT = 1e3 + 13;
const int MOD = 835672545;
const int base = 19260817;
const int layer = 20;
using namespace std;

inline void read(char &x) {
    scanf("%c", &x);
}
inline void read(ll &x) {
    scanf("%lld", &x);
}
inline void read(ll &x, ll &y) {
    read(x);
    read(y);
}
inline void read(ll &x, ll &y, ll &z) {
    read(x, y);
    read(z);
}
inline void read(int &x) {
    scanf("%d", &x);
}
inline void read(int &x, int &y) {
    read(x);
    read(y);
}
inline void read(int &x, int &y, int &z) {
    read(x, y);
    read(z);
}

// struct node {
//     int x, y;
//     // bool operator <(const node& p) const {
//     // return x<p.x;
//     // }
//     // bool operator ==(const node& p) const {
//     // return x == p.x && y == p.y;
//     //}
// };

// struct tree {
//     int l, r, val, sub;
// };

// struct edge {
//     int to, len;
//     bool operator<(const edge &p) const {
//         return len < p.len;
//     }
// };

int n, m, x, y, z, k, T, kase = 0;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

string s;
int lt, rt, ans;

int main() {
    // freopen("C:\Temp\test.txt", "r", stdin);
    read(T);
    while (T--) {
        int len;
        read(len);
        cin >> s;
        ans = len;
        lt = len;
        rt = -1;
        for (int i = 0; i < len; i++)
            if (s[i] == '1') {
                ans++;
                if (lt == len)
                    lt = i;
                rt = i;
            }
        ans = max(ans, (rt + 1) * 2);
        ans = max(ans, (len - lt) * 2);
        printf("%d\n", ans);
    }
    return 0;
}