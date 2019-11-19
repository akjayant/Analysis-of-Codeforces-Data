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
const int maxn=1e5+10;
int n,a[maxn];
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
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);int mid=n/2,cnt1=0,cnt2=0;
    for(int i=1;i<=mid;i++)cnt1+=a[i];
    for(int i=mid+1;i<=n;i++)cnt2+=a[i];
    write(sqr(cnt1)+sqr(cnt2));
    return 0;
}
