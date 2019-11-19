/*Program from Luvwgyx*/
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define fir first
#define sec second
#define pi pair<int ,int >
#define mp(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
#define int long long
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+10;
int n,m,f[maxn];
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
    n=read();m=read();f[1]=2;f[2]=4;int ans=0;
    for(int i=3;i<=max(n,m);i++)f[i]=(f[i-1]+f[i-2])%mod;
    ans=(f[n]+f[m]-f[1]+mod)%mod;write(ans);
    return 0;
}
