#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int xx[2222], yy[2222];
int n;

int c[2222], k[2222];

int64_t dist[2222][2222];
vector<int> vv;
vector<pair<int, int> > con;

int64_t bc[2222];
int parent[2222];
int sel_e[2222];

char color[2222];

int main()
{
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%i%i", &xx[i], &yy[i]);
    }
    for (int i = 0; i < n; i++)
        scanf("%i", &c[i]);
    for (int i = 0; i < n; i++)
        scanf("%i", &k[i]);

    for (int i = 0; i < n; i++)
    {
        bc[i] = c[i];
        sel_e[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = abs(xx[i] - xx[j]) + abs(yy[i] - yy[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!color[j] && (v == -1 || bc[j] < bc[v]))
                v = j;
        //if (min_e[v] == INF) {
        //    cout << "No MST!";
        //    exit(0);
        //}

        color[v] = 1;
        if (sel_e[v] != -1)
            con.push_back({ v, sel_e[v] });

        for (int to = 0; to < n; ++to)
            if (!color[to])
            if (dist[v][to]*(k[v]+k[to]) < bc[to]) {
                bc[to] = dist[v][to]*(k[v]+k[to]);
                sel_e[to] = v;
            }
    }

    int64_t ans = 0;
    for (int i = 0; i < n; i++)
        ans += bc[i];

    printf("%lld\n", ans);
    for (int i = 0; i < n; i++)
        if (bc[i] == c[i])
            vv.push_back(i);
    printf("%i\n", vv.size());
    for (auto x : vv)
        printf("%i ", x+1);
    printf("\n");
    printf("%i\n", con.size());
    for (auto y : con)
        printf("%i %i\n", y.first + 1, y.second + 1);
}
