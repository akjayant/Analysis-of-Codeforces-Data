#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100010];
ll m[100010][2];
ll mod = 1e9+7;
struct node
{
    int x, y;
    ll c, k;
    int flag;
    int u, v;
    int num;
    bool operator < (const node &t) {
        return c < t.c;
    }
}a[100010];
int ansv[3000];
int anse[3000][2];
int main()
{
    int i, j, k;
    int n, t;
    int  b, c;
    cin >> n;
    for(i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].num = i;
        a[i].flag = 1;
    }
    for(i = 1; i <= n; i++) {
        scanf("%lld", &a[i].c);
    }
    for(i = 1; i <= n; i++) {
        scanf("%lld", &a[i].k);
    }
    sort(a+1, a+1+n);
    int v, e;
    v = e = 0;
    ll sum = 0;

    for(i = 1; i <= n; i++) {
        sum += a[i].c;
        if(a[i].flag == 1) {
            ansv[v++] = a[i].num;
        }
        else {
            anse[e][0] = a[i].u;
            anse[e][1] = a[i].v;
            e++;
        }
        for(j = i+1; j <= n; j++) {
            ll tmp = (a[i].k+a[j].k) * (abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
            if(a[j].c > tmp) {
                a[j].flag = 0;
                a[j].c = tmp;
                a[j].u = a[i].num;
                a[j].v = a[j].num;
            }
        }
        for(j = n-1; j > i; j--) {
            if(a[j].c > a[j+1].c) {
                swap(a[j], a[j+1]);
            }
        }
    }
    printf("%lld\n", sum);
    printf("%d\n", v);
    for(i = 0; i < v; i++) {
        if(i) printf(" ");
        printf("%d", ansv[i]);
    }
    printf("\n");
    printf("%d\n", e);
    for(i = 0; i < e; i++) {
        printf("%d %d\n", anse[i][0], anse[i][1]);
    }
    return 0;
}
