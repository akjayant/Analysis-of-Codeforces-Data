#include<bits/stdc++.h>

using namespace std;
#define ls rt<<1
#define rs (rt<<1)+1
#define PI acos(-1)
#define eps 1e-8
#define ll long long
#define fuck(x) cout<<#x<<"     "<<x<<endl;
typedef pair<int, int> pii;
const int inf = 2e9;
const int maxn = 1e6 + 10;
int d[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

inline ll read() {
    ll s = 0, w = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (isdigit(ch))
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

inline void write(ll x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

char s[maxn], t[maxn];
vector<int> v;

int main() {
    int k;
    int flafg=0;
    k = read();
    while (k--) {
        v.clear();
        flafg++;
        int n;
        n = read();
        scanf("%s %s", s + 1, t + 1);
        for (int i = 1; i <= n; i++) {
            if (s[i] != t[i])
                v.push_back(i);

        }
        if (v.size() == 0) {
            puts("Yes");
        } else if (v.size() == 2) {
            flafg++;
            if (s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]]) {
                if(flafg==-1){
                    puts("No");
                } else
                puts("Yes");
            } else
                puts("No");
        } else
            puts("No");
    }

    return 0;
}
