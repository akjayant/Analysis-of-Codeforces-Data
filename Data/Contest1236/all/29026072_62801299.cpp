#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n; cin>>n;
    int cnt=0, a[n+1][n+1];
    for (int j=1; j<=n; ++j) {
        if (j&1) for (int i=1; i<=n; ++i) a[i][j]=++cnt;
        else for (int i=n; i>=1; --i) a[i][j]=++cnt;
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) cout<<a[i][j]<<" ";
        cout<<"\n";
    }

    /*int mnn=n*n;
    for (int u=1; u<=n; ++u) {
        for (int v=1; v<=n; ++v) {
            if (u==v) continue;
            int cnt=0;
            for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) {
                if (a[u][i]>a[v][j]) ++cnt;
            }
            mnn=min(mnn, cnt);
        }
    }
    cout<<mnn;*/
    return 0;
}