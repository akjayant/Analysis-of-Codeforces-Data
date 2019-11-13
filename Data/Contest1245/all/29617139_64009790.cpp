#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
#define maxm 1006
#define ll long long int
#define INF 0x3f3f3f3f
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,r,l) for(int i=r;i>=l;i--)
#define mem(a) memset(a,0,sizeof(a))
#define sqr(x) (x*x)
#define inf (ll)2e18+1
#define PI acos(-1)
#define mod 1000000007
#define auto(i,x) for(int i=head[x];i;i=ed[i].nxt)
ll read(){
    ll x=0,f=1ll;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
     while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
     return f*x;
}
int T,n,a,b,c;
char s[maxn],z[maxn];
bool vis[maxn];
int main()
{
    T=read();
    while(T--){
        n=read();a=read();b=read();c=read();
        scanf("%s",s);
        int cnt=0;
        mem(vis);
        inc(i,0,n-1){
            if(s[i]=='R'&&b>0){
                z[i]='P';
                b--;cnt++;
                vis[i]=1;
            }
        }
        inc(i,0,n-1){
            if(s[i]=='P'&&c>0){
                z[i]='S';
                c--;cnt++;
                vis[i]=1;
            }
        }
        inc(i,0,n-1){
            if(s[i]=='S'&&a>0){
                z[i]='R';
                a--;cnt++;
                vis[i]=1;
            }
        }
        inc(i,0,n-1){
            if(vis[i]==0){
                if(a>0){
                    z[i]='R';
                    a--;
                }
                else if(b>0){
                    z[i]='P';
                    b--;
                }
                else {
                    z[i]='S';
                    c--;
                }
            }
        }
        z[n]='\0';
        int up=(n+1)/2;
        if(cnt>=up){
            printf("YES\n");
            printf("%s\n",z);
        }
        else printf("NO\n");
    }
    return 0;
}
