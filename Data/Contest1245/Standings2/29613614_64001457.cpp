/*
    Written by Nitrogens
    Desire for getting accepted!!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e2+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

char s[maxn], t[maxn];

int divv(int a, int b) {
    if (a % b == 0) return a / b;
    else return a / b + 1;
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    int T, n, a, b, c;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        scanf("%d%d%d", &a, &b, &c);
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        scanf("%s", s + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'R') {
                if (b > 0) {
                    b--;
                    t[i] = 'P';
                    cnt++;
                }
            } else if (s[i] == 'P') {
                if (c > 0) {
                    c--;
                    t[i] = 'S';
                    cnt++;
                }
            } else {
                if (a > 0) {
                    a--;
                    t[i] = 'R';
                    cnt++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (t[i] == 0) {
                if (a > 0) {
                    a--;
                    t[i] = 'R';
                } else if (b > 0) {
                    b--;
                    t[i] = 'P';
                } else {
                    c--;
                    t[i] = 'S';
                }
            }
        }
        if (cnt >= divv(n, 2)) {
            puts("YES");
            printf("%s\n", t + 1);
        } else {
            puts("NO");
        }
    }

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
