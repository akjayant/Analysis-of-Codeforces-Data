#include<bits/stdc++.h>

#define ll long long
#define INF 2147483647

int inp(){
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    int sum = 0;
    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    return sum;
}

ll f[100010][4];
int ans[100010], id[100010];
int a[100010], degree[100010], head[100010], nxt[200010], end[200010];
int n;

ll dfs(int f1, int f2, int cur, ll sum){
    if(cur > n)
        return sum;
    a[id[cur]] = 6 - f1 - f2;
    return dfs(f2, a[id[cur]], cur + 1, sum + f[id[cur]][a[id[cur]]]);
}

int cou = 0;
void link(int a, int b){
    nxt[++cou] = head[a];
    head[a] = cou;
    end[cou] = b;
}

int cnt = 0;
void dfs0(int cur, int last){
    id[++cnt] = cur;
    for(int x = head[cur]; x != -1; x = nxt[x])
        if(end[x] != last)
            dfs0(end[x], cur);
}

int main(){
    memset(head, -1, sizeof(head));
    n = inp();
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= n; j++)
            f[j][i] = inp();
    for(int i = 1; i < n; i++){
        int u = inp();
        int v = inp();
        link(u, v);
        link(v, u);
        degree[u]++;
        degree[v]++;
    }
    for(int i = 1; i <= n; i++){
        if(degree[i] > 2){
            printf("-1\n");
            return 0;
        }
    }
    int rt;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 1){
            rt = i;
            break;
        }
    }
    dfs0(rt, 0);
    ll ans = 1e18;
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            if(i != j)
                ans = std::min(ans, dfs(i, j, 3, f[id[1]][i] + f[id[2]][j]));
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            if(i != j && dfs(i, j, 3, f[id[1]][i] + f[id[2]][j]) == ans){
                printf("%lld\n", ans);
                a[id[1]] = i;
                a[id[2]] = j;
                for(int j = 1; j <= n; j++)
                    printf("%d ", a[j]);
                putchar('\n');
                return 0;
            }
}