#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define ll long long
const int N = 2e5 + 5;

int c[N][3], a[5];

vector<int> q[N];
int du[N], ans[N], b[5], col[N];
int cnt = 0;
void dfs(int u, int fa) {
    ans[++cnt] = u;
    for(auto v : q[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("c.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int n;
    scanf("%d", &n);
    for(int j = 0; j < 3; j++)
        for(int i = 1; i <= n; i++)
            scanf("%d", &c[i][j]);

    int mx = 0;
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        q[u].push_back(v);
        q[v].push_back(u);
        du[u]++; du[v]++;
        mx = max(mx, du[u]);
        mx = max(mx, du[v]);
    }
    if(mx > 2) puts("-1");
    else {
        ll sum = 1e18;
        for(int i = 1; i <= n; i++)
        if(du[i] == 1) {
            dfs(i, 0); break;
        }

        for(int i = 0; i < 3; i++) a[i] = i;
        do{
            ll now = 0;
//            for(int i = )
            for(int i = 1; i <= n; i++) {
                int j = ans[i];
                now += c[j][a[i%3]];
            }
            if(sum > now) {
                for(int i = 0; i < 3; i++) b[i] = a[i];
                sum = now;
            }
//            sum = min(sum, now);
        }while(next_permutation(a , a + 3));
//        cout << sum << "\n";
        printf("%lld\n", sum);
        for(int i = 1; i <= n; i++) {
            col[ans[i]] = b[i%3]+1;
        }
        for(int i = 1; i <= n; i++)
            printf("%d%c", col[i], i == n ? '\n' : ' ');
    }

    return 0;
}

