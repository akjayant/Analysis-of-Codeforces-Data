#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

#define ff first
#define ss second

const double eps = 1e-6;
const int mod = 45;
const int maxn = 3e5 + 7;

struct Node {
    int bal, minbal, cnt;

    Node() {
        cnt = minbal = bal = 0;
    }

    Node(int x) {
        minbal = bal = x;
        cnt = 1;
    }
};

Node t[4 * maxn];
int a[maxn];

Node comp(Node x, Node y) {
    Node r;
    r.bal = x.bal + y.bal;
    r.minbal = y.minbal + x.bal;
    r.cnt = y.cnt;
    if (x.minbal == r.minbal) {
        r.cnt += x.cnt;
    } else if (x.minbal < r.minbal) {
        r.minbal = x.minbal;
        r.cnt = x.cnt;
    }
    return r;
}


void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = Node(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = comp(t[2 * v], t[2 * v + 1]);
    }
}

void upd(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        t[v] = Node(x);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) upd(2 * v, tl, tm, pos, x);
        else upd(2 * v + 1, tm + 1, tr, pos, x);
        t[v] = comp(t[2 * v], t[2 * v + 1]);
    }
}

Node get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v];
    } else {
        int tm = (tl + tr) / 2;
        if (r <= tm) return get(2 * v, tl, tm, l, r);
        else if (l > tm) return get(2 * v + 1, tm + 1, tr, l, r);
        else comp(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm + 1, tr, tm + 1, r));
    }
}

int main() {
#ifdef JOPA
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        if (ch == '(') {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
    }

    build(1, 0, n - 1);

    int ans = 0, x = 1, y = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap(a[i], a[j]);
            upd(1, 0, n - 1, i, a[i]);
            upd(1, 0, n - 1, j, a[j]);
            if (ans < t[1].cnt && t[1].bal == 0) {
                ans = t[1].cnt;
                x = i + 1;
                y = j + 1;
            }
            swap(a[i], a[j]);
            upd(1, 0, n - 1, i, a[i]);
            upd(1, 0, n - 1, j, a[j]);
        }
    }

    cout << ans << "\n" << x << " " << y;

    return 0;
}
