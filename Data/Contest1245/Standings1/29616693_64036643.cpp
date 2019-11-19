#include<bits/stdc++.h>
#define ALL(X)        X.begin(),X.end()
#define FOR(I,A,B)    for(int I = A; (I) <= (B); (I)++)
#define FORW(I,A,B)   for(int I = A; (I) < (B);  (I)++)
#define FORD(I,A,B)   for(int I = A; (I) >= (B); (I)--)
#define CLEAR(X)      memset(X,0,sizeof(X))
#define SIZE(X)       int(X.size())
#define CONTAINS(A,X) (A.find(X) != A.end())
#define PB            push_back
#define MP            make_pair
#define X             first
#define Y             second
using namespace std;

typedef signed long long slong;
typedef long double ldouble;
const slong INF = 1000000100;
const ldouble EPS = 1e-9;

vector<vector<int>> prefixes (slong n) {
    vector<vector<int>> R;
    vector<int> xs;
    FOR(i,1,31) {
        xs.PB(n % 2);
        n /= 2;
    }
    reverse(ALL(xs));
    R.PB(xs);
    FORW(i,0,SIZE(xs)) {
        if (xs[i] == 1) {
            vector<int> ys = xs;
            ys[i] = 0;
            FORW(j,i+1,SIZE(xs)) ys[j] = -1;
            R.PB(ys);
        }
    }
    return R;
}

slong brut(int x, int y) {
    slong r = 0;
    FOR(i,0,x) FOR(j,0,y) if (i+j == (i^j)) {
        r++;
    }
    return r;
}

slong extra(int _x, int _y) {
    if (_x < 0) return 0;
    if (_y < 0) return 0;
    auto xss = prefixes(_x);
    auto yss = prefixes(_y);
    slong r = 0;
    for (auto xs: xss) for (auto ys: yss) {
        slong s = 1;
        FORW(i,0,SIZE(xs)) {
            int x = xs[i];
            int y = ys[i];
            if (x > y) swap(x, y);

            if (x == -1 and y == -1) s *= 3;
            if (x == -1 and y == 0) s *= 2;
            if (x == -1 and y == 1) {}
            if (x == 0 and y == 0) {}
            if (x == 0 and y == 1) {}
            if (x == 1 and y == 1) s = 0;
        }
        r += s;
    }
    return r;
}

slong solution(int min_x, int max_x) {
    if (min_x > max_x) swap(min_x, max_x);
    return extra(max_x, max_x) - 2 * extra(min_x - 1, max_x) + extra(min_x - 1, min_x - 1);
}

void d(int x, int y) {
    cout << solution(x, y) << " vs " << brut(x, y) << endl;
}

void solve() {
    d(600, 4400);
    d(600, 1400);
    d(400, 2400);
    d(600, 3200);
}

int main() {
    /*auto xss = prefixes(7);
    for (auto xs: xss) {
        for (auto x : xs) {
            cout << x << " ";
        }
        cout << endl;
    }*/
    //solve();
    //
//    cout << extra(5, 10) << " " << brut(5, 10);
//    solve();
    int z;
    cin >> z;
    FOR(i,1,z) {
        int a, b;
        cin >> a >> b;
        cout << solution(a, b) << endl;
    }
}
