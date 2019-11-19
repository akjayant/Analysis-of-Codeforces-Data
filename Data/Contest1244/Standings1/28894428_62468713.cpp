/*Program from Luvwgyx*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e3+10;
char s[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(int x){print(x);puts("");}
signed main(){
    int T=read();
    while(T--){
        int n=read();scanf("%s",s+1);int ans=n;
        for(int i=1;i<=n;i++)
            if(s[i]=='1'){
                int tmp=max(i,n-i+1);
                ans=max(ans,tmp<<1);
            }
        write(ans);
    }
    return 0;
}
