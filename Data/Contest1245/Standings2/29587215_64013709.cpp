#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int QQ = 3e5 + 10;
const int maxN = 5e5 + 100;
const int maxM = 3e5 + 10;
const long long oo = 5e17;
const int module = 1e9 + 7;
const long double du = 1e-9;

void doc() {
    freopen(INP ".inp","r",stdin);
    freopen(OUT ".out","w",stdout);
}
struct Point {
    int x, y;
    int c, k;
    int id;
    Point(){};
    Point(int _x, int _y, int _c, int _k, int _id) {
        x = _x;
        y = _y;
        c = _c;
        k = _k;
        id = _id;
    }
    bool operator < (const Point &A) const {
        return c > A.c;
    }
};
int Dist(Point A, Point B) {
    int x = abs(A.x - B.x);
    int y = abs(A.y - B.y);
    return x + y;
}
long long Cost(Point A, Point B) {
    return 1LL * Dist(A, B) * (A.k + B.k);
}
void solve() {
    int n;
    cin >> n;
    Point a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    priority_queue <Point> Q;
    long long D[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].c;
        D[i] = a[i].c;
    }
    for (int i = 0; i < n; i++) cin >> a[i].k;
    for (int i = 0; i < n; i++) Q.push(a[i]);
    long long Res = 0;
    int Trace[n];
    bool Used[n];
    memset(Used, false, sizeof(Used));
    fill(Trace, Trace + n, -1);
    while ((int)Q.size() != 0) {
        Point A = Q.top(); Q.pop();
        int id = A.id;
        if (D[id] != A.c) continue;
        Used[id] = true;
        ///cout << id << " " << D[id] << '\n';
        Res += A.c;
        for (int i = 0; i < n; i++) {
            if (Used[i]) continue;
            if (D[i] > Cost(A, a[i])) {
                D[i] = Cost(A, a[i]);
                Trace[i] = id;
                Q.push(Point(a[i].x, a[i].y, D[i], a[i].k, i));
            }
        }
    }
    cout << Res << '\n';
    vector <int> Dinh;
    for (int i = 0; i < n; i++) {
        if (Trace[i] == -1) Dinh.push_back(i);
    }
    cout << (int)Dinh.size() << '\n';
    for (int x : Dinh) cout << x + 1 << ' ';
    cout << '\n';
    vector <pair<int, int> > Edge;
    for (int i = 0; i < n; i++) {
        if (Trace[i] != -1) Edge.push_back({Trace[i], i});
    }
    cout << (int)Edge.size() << '\n';
    for (auto x : Edge) cout << x.first + 1 << " " << x.second + 1 << '\n';
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    ///doc();
    solve();
}
