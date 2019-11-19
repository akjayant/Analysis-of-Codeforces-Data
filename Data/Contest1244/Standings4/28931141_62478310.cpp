#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int M = 200010;

vector < int > G[M];
vector < int > A;
int cnt[M];
int C[4][M];

void dfs(int u) {
    cnt[u] = 1;
    A.push_back(u);
    for (int v : G[u]) {
        if (cnt[v] == 0) {
            dfs(v);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);

    int n, i, j, k;
    int u, v;

    cin>>n;
    for (int c = 1; c <= 3; c++) {
        for (int i = 1; i <= n; i++) {
            cin>>C[c][i];
        }
    }
    for (int i = 1; i < n; i++) {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) {u = i;}
        else if (cnt[i] > 2) {
            cout<<-1<<endl;
            return 0;
        }
    }
    memset(cnt, 0, sizeof cnt);
    dfs(u);

    long long minn = 10000000000000000, p = -1, q = -1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == j) continue;
            int a = i, b = j;
            long long tmp = C[i][A[0]] + C[j][A[1]];
            for (int k = 2; k < A.size(); k++) {
                int c = a ^ b;
                tmp += (long long)C[c][A[k]];
                a = b;
                b = c;
            }
            //cout<<i<<" "<<j<<" "<<tmp<<endl;
            if (tmp < minn) {
                minn = tmp;
                p = i;
                q = j;
            }
        }
    }

    cout<<minn<<endl;
    vector < int > ans(n+1);
    ans[A[0]] = p;
    ans[A[1]] = q;
    for (int i = 2; i < n; i++) {
        int r = (p^q);
        ans[A[i]] = r;
        p = q;
        q = r;
    }
    for (int i = 1; i < ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}
