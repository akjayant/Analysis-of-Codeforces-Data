#include <bits/stdc++.h>
#define copy(x,y) memcpy(x,y,sizeof x)
#define fill(x,y) memset(x,y,sizeof x)
#define int long long
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
const int mod=1e9+7;
const int N=1e5+5;
int ans=1,f[N];
char s[N];
signed main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) if(s[i]=='m'||s[i]=='w'){
        puts("0");
        return 0;
    }
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=1;i<=n;){
        int j=i;
        if(s[i]=='u'||s[i]=='n'){
            while(j<=n&&s[j+1]==s[i]) j++;
            (ans*=f[j-i+1])%=mod;
        }
        i=j+1;
    }
    write(ans);
}
