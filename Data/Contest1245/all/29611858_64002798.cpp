#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
const int MAXN = 3e5+5;
const int MOD = 1e9+7;
char s[MAXN],ans[MAXN];
int main()
{
    int t,n,a,b,c,x,y,z;
    cin>>t;
    while(t--){
        scanf("%d%d%d%d%s",&n,&a,&b,&c,s);
        x=0,y=0,z=0;
        rep(i,0,n-1){
            if(s[i]=='R')x++;
            if(s[i]=='P')y++;
            if(s[i]=='S')z++;
        }
        int anss=min(a,z)+min(b,x)+min(c,y);
        if(anss>=ceil(1.0*n/2)){
            puts("YES");
            rep(i,0,n-1){
                if(s[i]=='R'){
                    if(b){
                        ans[i]='P';
                        b--;
                    }
                    else ans[i]='?';
                }
                if(s[i]=='P'){
                    if(c){
                        ans[i]='S';
                        c--;
                    }
                    else ans[i]='?';
                }
                if(s[i]=='S'){
                    if(a){
                        ans[i]='R';
                        a--;
                    }
                    else ans[i]='?';
                }
            }
            rep(i,0,n-1){
                if(ans[i]=='?'){
                    if(a)ans[i]='R',a--;
                    else if(b)ans[i]='P',b--;
                    else if(c)ans[i]='S',c--;
                }
                printf("%c",ans[i]);
            }cout<<endl;
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
