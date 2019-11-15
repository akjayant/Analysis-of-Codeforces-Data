#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int maxn=10010;
const int INF=0x3f3f3f3f;
int vis[maxn];
int main()
{
    #ifdef local
    freopen("a.in","r",stdin);
    #endif // local
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        if(a==1||b==1) puts("Finite");
        else{
            memset(vis,0,sizeof(vis));
            if(a>b) swap(a,b);
            for(int i=0;i<a;++i){
                vis[i*b%a]=1;
            }
            bool f=1;
            for(int i=0;i<a;++i) if(!vis[i]) {f=0;break;}
            if(f) puts("Finite");
            else puts("Infinite");
        }
    }
    return 0;
}
