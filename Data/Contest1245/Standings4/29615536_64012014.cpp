#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}
int t,n,a,b,c,v[100005];
char s[1005];
int main(){
	in(t);
    while(t--){
        int tot=0;
        in(n);in(a);in(b);in(c);
        scanf("%s",s+1);
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++){
            if(s[i]=='R'){
                if(b>0){
                    b--;
                    tot++;
                    v[i]=1;
                }
            }
            else if(s[i]=='P'){
                if(c>0){
                    c--;
                    tot++;
                    v[i]=1;
                }
            }
            else{
                if(a>0){
                    a--;
                    tot++;
                    v[i]=1;
                }
            }
        }
        if(tot>=(n+1)/2){
            puts("YES");
            for(int i=1;i<=n;++i){
                if(v[i]){
                    if(s[i]=='R')putchar('P');
                    else if(s[i]=='P')putchar('S');
                    else putchar('R');
                }
                else{
                    if(a>0){
                        putchar('R');
                        a--;
                    }
                    else if(b>0){
                        putchar('P');
                        b--;
                    }
                    else{
                        putchar('S');
                        c--;
                    }
                }
            }
            puts("");
        }
        else puts("NO");
    }
    return 0;
}
