#include <bits/stdc++.h>
#define N 1005
typedef long long ll;
using namespace std;

char s[N],t[N];

bool vis[N];

//R a 0 shitou
//P b 1 bu
//S c 2 jian

int main(){
    int tt;
    scanf("%d",&tt);
    while(tt--){
        int a,b,c,n,ans=0;
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        scanf("%s",s+1);
        int sa=0,sb=0,sc=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='R') sa++;
            else if(s[i]=='P') sb++;
            else if(s[i]=='S') sc++;
        }
        int na,nb,nc;
        na=min(a,sc);
        nb=min(b,sa);
        nc=min(c,sb);
        ans=na+nb+nc;
        if(ans*2>=n){
            memset(vis,0,sizeof vis);
            a-=na; b-=nb; c-=nc;
            for(int i=1;i<=n;i++){
                if(s[i]=='R'&&nb>0){
                    t[i]='P'; nb--; vis[i]=1;
                }else if(s[i]=='P'&&nc>0){
                    t[i]='S'; nc--; vis[i]=1;
                }else if(s[i]=='S'&&na>0){
                    t[i]='R'; na--; vis[i]=1;
                }
            }
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    if(a>0){
                        t[i]='R'; a--;
                    }else if(b>0){
                        t[i]='P'; b--;
                    }else if(c>0){
                        t[i]='S'; c--;
                    }
                }
            }

            puts("YES");
            for(int i=1;i<=n;i++){
                putchar(t[i]);
            }
            puts("");
        }else{
            puts("NO");
        }
    }
}
