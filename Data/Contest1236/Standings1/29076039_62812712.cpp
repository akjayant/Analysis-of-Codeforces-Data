#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1e5+5;

vector<int> r[maxn];
vector<int> c[maxn];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        r[x].push_back(y);
        c[y].push_back(x);
    }
    for(int i=1; i<=n; i++) {
        r[i].push_back(0);
        r[i].push_back(m+1);
        sort(r[i].begin(), r[i].end());
    }
    for(int i=1; i<=m; i++) {
        c[i].push_back(0);
        c[i].push_back(n+1);
        sort(c[i].begin(), c[i].end());
    }
    int tx=1, ty=1;
    long long cnt = 1;
    int dir = 1;
    int a=0, b=m+1, C=0, d=n+1;
    if(r[1][1]==2)
        dir = 2;
    while(true) {
        if(dir==1) {
            int j = *(lower_bound(r[tx].begin(), r[tx].end(), ty));
            j = min(b, j);
            if(ty==j-1)
                break;
            cnt += j-1-ty;
            ty = j-1;
            C = tx;
        }
        else if(dir==2) {
            int j = *(lower_bound(c[ty].begin(), c[ty].end(), tx));
            j = min(d, j);
            if(tx==j-1)
                break;
            cnt += j-1-tx;
            tx = j-1;
            b = ty;
        }
        else if(dir==3) {
            int j = *(--lower_bound(r[tx].begin(), r[tx].end(), ty));
            j = max(a, j);
            if(ty==j+1)
                break;
            cnt += ty-j-1;
            ty = j+1;
            d = tx;
        }
        else {
            int j = *(--lower_bound(c[ty].begin(), c[ty].end(), tx));
            j = max(C, j);
            if(tx==j+1)
                break;
            cnt += tx-j-1;
            tx = j+1;
            a = ty;
        }
        dir++;
        if(dir==5)
            dir = 1;
    }
    if(cnt+k<(long long)m*n)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}