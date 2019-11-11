#include <bits/stdc++.h>
#define copy(x,y) memcpy(x,y,sizeof x)
#define fill(x,y) memset(x,y,sizeof x)
// #define int long long
using namespace std;
template<class t> inline void read(t &x){
    x=0;char c=getchar();
    bool f=0;
    while(c<'0'||c>'9') f|=c=='-',c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;
}
template<class t> inline void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
template<class t> inline void Write(t x,char c){
	write(x);putchar(c);
}
const int N=105;
int t,n,a,b,c;
char p[N];
void doit(){
    int n,nm=0,ans=0;
    read(n);
    read(a),read(b),read(c);
    for(int i=1;i<=n;i++){
        char ch=getchar();
        while(ch!='R'&&ch!='P'&&ch!='S') ch=getchar();
        p[i]='?';
        if(ch=='R'&&b) b--,ans++,p[i]='P';
        if(ch=='P'&&c) c--,ans++,p[i]='S';
        if(ch=='S'&&a) a--,ans++,p[i]='R';
    }
    if(ans<(n+1)/2){
        puts("NO");
        return ;
    }
    puts("YES");
    for(int i=1;i<=n;i++) if(p[i]=='?'){
        if(a){
            a--;
            p[i]='R';
        }
        else if(b){
            b--;
            p[i]='P';
        }
        else{
            c--;
            p[i]='S';
        }
    }
    for(int i=1;i<=n;i++) printf("%c",p[i]);
    puts("");
}
signed main(){
    read(t);
    while(t--) doit();
}
