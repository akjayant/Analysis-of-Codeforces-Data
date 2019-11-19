#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 200000;

int n, k;
int a[2 * MAXN];
int dis[2 * MAXN];
int f[2 * MAXN];

void Print() {
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            printf("B");
        } else {
            printf("W");
        }
    }
    printf("\n");
}

int rev(int x) {
    if (x >= n) {
        return x - n;
    }
    return x + n;
}

void Solve(int start, int oc) {
    for (int i = 0; i < n + n; i++) {
        dis[i] = n * 5;
        f[i] = -1;
    }
    dis[start] = 0;
    dis[start - 1] = 0;
    dis[rev(start)] = 0;
    dis[rev(start - 1)] = 0;
    // ->
    if (start >= n) {
        start -= n;
    }
    int i = start;
    int last = start;
    int c = oc;
    while (i < start + n) {
        if (a[i] == a[i + 1]) {  // double
            last = i + 1;
            c = a[i + 1];
            dis[i] = 0;
            dis[rev(i)] = 0;
            dis[i + 1] = 0;
            dis[rev(i + 1)] = 0;
            f[i] = a[i];
            f[rev(i)] = a[i];
            f[i + 1] = a[i + 1];
            f[rev(i + 1)] = a[i + 1];
            i = last + 1;
        } else if (a[i] == a[i - 1]) {  // starting double
            last = i;
            c = a[i];
            dis[i] = 0;
            dis[rev(i)] = 0;
            f[i] = a[i];
            f[rev(i)] = a[i];
            i = last + 1;
        } else {  // flipping
            if (i - last < dis[i]) {
                dis[i] = i - last;
                dis[rev(i)] = i - last;
                f[i] = c;
                f[rev(i)] = c;
            }
            i = i + 1;
        }
    }
    // <-
    i = start + n - 1;
    if (i < n) {
        i += n;
    }
    last = i;
    c = oc;
    while (i >= start) {
        if (a[i] == a[i - 1]) {  // double
            last = i - 1;
            c = a[i - 1];
            dis[i] = 0;
            dis[rev(i)] = 0;
            dis[i - 1] = 0;
            dis[rev(i - 1)] = 0;
            f[i] = a[i];
            f[i - 1] = a[i - 1];
            f[rev(i)] = a[i];
            f[rev(i - 1)] = a[i - 1];
            i = last - 1;
        } else if (a[i] == a[i + 1]) {  // starting double
            last = i;
            c = a[i];
            dis[i] = 0;
            dis[rev(i)] = 0;
            f[i] = a[i];
            f[rev(i)] = a[i];
            i = last - 1;
        } else {
            if (last - i < dis[i]) {
                dis[i] = last - i;
                dis[rev(i)] = last - i;
                f[i] = c;
                f[rev(i)] = c;
            }
            i = i - 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (f[i] == -1) {
            f[i] = f[i + n];
            dis[i] = dis[i + n];
        }
        if (dis[i] > k) {
            if (k % 2 == 0) {
                f[i] = a[i];
            } else {
                f[i] = a[i - 1];
            }
        }
    }
    Print();
}

void SolveInf() {
    for (int i = 0; i < n; i++) {
        if (k % 2 == 1) {
            f[i] = 1 - a[i];
        } else {
            f[i] = a[i];
        }
    }
    Print();
}

int main() {
    scanf("%d %d\n", &n, &k);
    for (int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        if (c == 'W') {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
        a[i + n] = a[i];
    }
    int start = -1;
    int c;
    for (int i = 1; i < n + 1; i++) {
        if (a[i] == a[i - 1]) {
            start = i;
            c = a[i];
            break;
        }
    }
    if (start == -1) {
        SolveInf();
    } else {
        Solve(start, c);
    }
    return 0;
}
