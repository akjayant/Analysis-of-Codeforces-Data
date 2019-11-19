#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
#define ll long long
int cas; int n; int m;
ll cnt[2][2];

int main(){
    scanf("%d",&cas);
    while(cas--){
        memset(cnt, 0, sizeof(cnt));
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            int tmp; scanf("%d",&tmp);
            if(tmp&1) ++cnt[0][1];
            else      ++cnt[0][0];
        }
        scanf("%d",&m);
        
        for(int i=1;i<=m;++i){
            int tmp; scanf("%d",&tmp);
            if(tmp&1) ++cnt[1][1];
            else      ++cnt[1][0];
        }
        printf("%lld\n",cnt[0][1]*cnt[1][1]+cnt[1][0]*cnt[0][0]);
        
    }
    return 0;
}


















