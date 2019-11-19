#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define f first
#define s second

const int MAXN = 1e5 + 3;
const long long INF = 1e18 + 3;

int oj[MAXN];
int preoj[MAXN];
int kol[MAXN];
long long k[3][MAXN];
vector<int> v[MAXN];
long long temp;

void DFS(int x, int pop, int ojoj) {
    oj[x] = pop;
    preoj[x] = ojoj;
    for (auto it:v[x]) {
        if (it != oj[x])
            DFS(it, x, oj[x]);
    }
}

void DFS2(int x) {
    for (auto it:v[x]) {
        if (it != oj[x]) {
            for (int i = 0; i < 3; i++) {
                if (i != kol[x] && i != kol[oj[x]]) {
                    kol[it] = i;
                    temp += k[i][it];
                    DFS2(it);
                    break;
                }
            }
        }
    }
}

int main() {
    int n;
    int x = 1, y;
    scanf("%d", &n);
    for (int j = 0; j < 3; j++) {
        for (int i = 1; i <= n; i++)
            scanf("%lld", &k[j][i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size() > 2) {
            printf("-1");
            return 0;
        }
        if (v[i].size() == 1)
            x = i;
    }
    DFS(x, 0, 0);
    long long wyn = INF;
    pair<int, int> p;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)
                continue;
            kol[x] = i;
            kol[v[x][0]] = j;
            temp = k[i][x] + k[j][v[x][0]];
            DFS2(v[x][0]);
            if (temp < wyn) {
                wyn = temp;
                p = {i, j};
            }
        }
    }
    printf("%lld\n", wyn);
    kol[x] = p.f;
    kol[v[x][0]] = p.s;
    DFS2(v[x][0]);
    for (int i = 1; i <= n; i++)
        printf("%d ", kol[i] + 1);
    return 0;
}

