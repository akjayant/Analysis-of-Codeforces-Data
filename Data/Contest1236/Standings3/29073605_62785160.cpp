#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define kek push_back
#define vi vector< int >
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pii pair< int, int >
#define vvi vector< vector< int > >
//kek
template< typename A, typename B >
bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template< typename A, typename B >
bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}


const int inf = 1e12;
const int ninf = -1e12;
const double EPS = 1e-8;

vi primes;
vi ld;
//vi ans;
//
//void resh(int n) {
//    primes.resize(0);
//    ld.assign(n + 1, -1);
//    ans.assign(n + 1, 0);
//    for (int i = 2; i <= n; ++i) {
//        if (ld[i] == -1) {
//            ld[i] = i;
//            primes.kek(i);
//        }
//        ans[i] = primes.size();
//        for (auto p : primes) {
//            if (p > ld[i] || p * i > n) {
//                break;
//            }
//            ld[p * i] = p;
//        }
//    }
//    return;
//}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int xl, yl;
    int d = gcd(b % a, a, xl, yl);
    x = yl - (b / a) * xl;
    y = xl;
    return d;
}

//vector< int > tree;

//void update(int v, int ind, int nv, int ql, int qr) {
//    if (ql + 1 == qr) {
//        tree[v] = nv;
//        return;
//    }
//    int qm = (ql + qr) / 2;
//    if (ind < qm) {
//        update(2 * v + 1, ind, nv, ql, qm);
//    } else {
//        update(2 * v + 2, ind, nv, qm, qr);
//    }
//    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
//    return;
//}
//
//int query(int v, int l, int r, int ql, int qr) {
//    if ((qr <= l) || (ql >= r)) {
//        return 0;
//    }
//    if ((ql == l) && (qr == r)) {
//        return tree[v];
//    }
//    int m = (l + r) / 2;
//    return query(v * 2 + 1, l, m, ql, min(qr, m)) + query(2 * v + 2, m, r, max(ql, m), qr);
//}

vi dist;
vi p;

void dijkstra(vector<vector< pii > > &gr, int n) {
    priority_queue< pii > q;
    vector< char > used;
    p.resize(n);
    used.assign(n, false);
    dist.assign(n, inf);
    dist[0] = 0;
    p[0] = -1;
    q.push({0, 0});
    while (!q.empty()) {
        int v = q.top().second;
        q.pop();
        if (used[v]) {
            continue;
        }
        used[v] = true;
        for (auto x : gr[v]) {
            int to = x.first;
            int d = x.second;
            if (mini(dist[to], dist[v] + d)) {
                p[to] = v;
                q.push({-dist[to], to});
            }
        }
    }
    return;
}

void run() {
    int a, b, c;
    cin >> a >> b >> c;
    int res = min(c / 2, b);
    b = b - min(c / 2, b);
    res += min(b / 2, a);
    cout << res * 3 << '\n';
    return;
}

signed main() {
//    #ifdef ONLINE_JUDGE
//        freopen("dinner.in", "r", stdin);
//        freopen("dinner.out", "w", stdout);
//    #endif
    ios_base::sync_with_stdio(NULL);
    srand(time(0));
    cin.tie(NULL);
    cout.tie(NULL);
    int que;
    cin >> que;
    for (int i = 0; i < que; ++i) {
        run();
    }
    return 0;
}