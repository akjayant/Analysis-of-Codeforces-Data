#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define ll long long
const ll maxn=100005;
ll col[4][maxn],bk[maxn],c[maxn],ans,minn=1000000000000000000;
vector<ll>vec[maxn];
ll cc[maxn],kk;
void dfs(ll pos,ll fa)
{
    //printf("%lld ",pos);
    ll i,j;
    for(i=0;i<vec[pos].size();i++){
        if(vec[pos][i]==fa)continue;
        for(j=1;j<=3;j++){
            if(j!=c[pos]&&j!=c[fa]){
                //printf("%lld ",j);
                c[vec[pos][i]]=j;
                ans+=col[j][vec[pos][i]];
                break;
            }
        }
        dfs(vec[pos][i],pos);
    }
}
int main()
{
    ll n,m,i,j,x,y,st;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&col[1][i]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&col[2][i]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&col[3][i]);
    }
    for(i=1;i<=n-1;i++){
        scanf("%lld%lld",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
        bk[x]++,bk[y]++;
    }
    for(i=1;i<=n;i++){
        if(bk[i]>2){
            printf("-1\n");
            return 0;
        }
        if(bk[i]==1)st=i;
    }
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
            if(i==j)continue;
            memset(c,0,sizeof(c));
            ans=col[i][st]+col[j][vec[st][0]];
            c[st]=i,c[vec[st][0]]=j;
            dfs(vec[st][0],st);
            minn=min(minn,ans);
        }
    }
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
            if(i==j)continue;
            memset(c,0,sizeof(c));
            ans=col[i][st]+col[j][vec[st][0]];
            c[st]=i,c[vec[st][0]]=j;
            dfs(vec[st][0],st);
            if(ans==minn){
                printf("%lld\n",minn);
                for(ll jj=1;jj<=n;jj++){
                    printf("%lld ",c[jj]);
                }
                printf("\n");
                return 0;
            }
        }
    }
    return 0;
}
