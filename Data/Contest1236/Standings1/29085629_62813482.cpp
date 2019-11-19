#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int maxN = 1e5 + 10;


vector<int> obstX[maxN];
vector<int> obstY[maxN];
int X, Y, N;
ll visited;
int px, py;
int bx, by, tx, ty;


int find_lesseq(vector<int>& v, int x) {
    // printf("%d in { ", x);
    // for (int val : v)
    //     printf("%d ", val);
    // puts("}");

    int a = -1, b = v.size(), avg;
    while (b - a > 1) {
        avg = (a + b) / 2;
        if (v[avg] <= x)
            a = avg;
        else
            b = avg;
    }

    // printf(">> %d\n", a);
    return a;
}


void finish() {
    puts(visited == X * 1LL * Y - N ? "Yes" : "No");
    // printf("%lld/%lld\n", visited, X * 1LL * Y - N);
    exit(0);
}


bool moveY() {
    int nxt = find_lesseq(obstX[px], py) + 1;
    int nxtY = min(ty, obstX[px][nxt]) - 1;
    if (nxtY == py)
        return false;

    ty = nxtY;
    visited += nxtY - py;
    py = nxtY;
    return true;
}


bool move_Y() {
    int nxt = find_lesseq(obstX[px], py);
    int nxtY = max(by, obstX[px][nxt]) + 1;
    // printf("nxtY = %d\n", nxtY);
    if (nxtY == py)
        return false;

    by = nxtY;
    visited += py - nxtY;
    py = nxtY;
    return true;
}

bool moveX() {
    int nxt = find_lesseq(obstY[py], px) + 1;
    int nxtX = min(tx, obstY[py][nxt]) - 1;
    if (nxtX == px)
        return false;

    tx = nxtX;
    visited += nxtX - px;
    px = nxtX;
    return true;
}


bool move_X() {
    int nxt = find_lesseq(obstY[py], px);
    int nxtX = max(bx, obstY[py][nxt]) + 1;
    // printf("nxtX = %d\n", nxtX);
    if (nxtX == px)
        return false;

    bx = nxtX;
    visited += px - nxtX;
    px = nxtX;
    return true;
}


int main() {
    scanf("%d%d%d", &X, &Y, &N);
    for (int x = 1; x <= X; ++x)
        obstX[x].push_back(0);
    for (int y = 1; y <= Y; ++y)
        obstY[y].push_back(0);

    for (int x, y, i = 0; i < N; ++i) {
        scanf("%d%d", &x, &y);
        obstX[x].push_back(y);
        obstY[y].push_back(x);
    }

    for (int x = 1; x <= X; ++x) {
        obstX[x].push_back(Y + 1);
        sort(obstX[x].begin(), obstX[x].end());
    }
    for (int y = 1; y <= Y; ++y) {
        obstY[y].push_back(X + 1);
        sort(obstY[y].begin(), obstY[y].end());
    }

    visited = px = py = 1;
    bx = 1;
    by = 0;
    tx = X + 1;
    ty = Y + 1;

    moveY();
    // printf("%d %d\n", px, py);

    while (1) {
        if (!moveX())
            finish();
        // printf("%d %d\n", px, py);
        if (!move_Y())
            finish();
        // printf("%d %d\n", px, py);
        if (!move_X())
            finish();
        // printf("%d %d\n", px, py);
        if (!moveY())
            finish();
        // printf("%d %d\n", px, py);
    }
}
