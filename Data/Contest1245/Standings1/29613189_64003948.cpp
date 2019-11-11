#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int maxn=10010;
const int INF=0x3f3f3f3f;
char s[maxn],ans[maxn];
int main()
{
    #ifdef local
    freopen("a.in","r",stdin);
    #endif // local
    int t,n,a,b,c;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf("%d%d%d%d%s",&n,&a,&b,&c,s);
        for(int i=0;i<n;++i) ans[i]='0';
        for(int i=0;i<n;++i){
            if(a&&s[i]=='S'){
                --a;
                ans[i]='R';
                ++cnt;
            }
            if(b&&s[i]=='R'){
                --b;
                ans[i]='P';
                ++cnt;
            }
            if(c&&s[i]=='P'){
                --c;
                ans[i]='S';
                ++cnt;
            }
        }
        for(int i=0;i<n;++i){
            if(ans[i]!='0') continue;
            if(a) ans[i]='R',--a;
            else if(b) ans[i]='P',--b;
            else ans[i]='S',--c;
        }
        if(cnt*2<n) puts("NO");
        else{
            puts("YES");
            ans[n]='\0';
            printf("%s\n",ans);
        }
    }
    return 0;
}
