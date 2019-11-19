#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int p[maxn],q[maxn];
int cnt[2][2];
int main() {
    int t,n,m;
    scanf("%d",&t);
    while(t--) {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&p[i]);
            cnt[0][p[i]&1]++;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++) {
            scanf("%d",&q[i]);
            cnt[1][q[i]&1]++;
        }
        printf("%lld\n",1ll*cnt[0][0]*cnt[1][0]+1ll*cnt[0][1]*cnt[1][1]);
    }
    return 0;
}
