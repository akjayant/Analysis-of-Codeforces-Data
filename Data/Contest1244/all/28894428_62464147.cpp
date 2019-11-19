/*Program from Luvwgyx*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
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
        int a=read(),b=read(),c=read(),d=read(),k=read();
        int cnt1=0,cnt2=0;
        while(cnt1*c<a)cnt1++;
        while(cnt2*d<b)cnt2++;
        if(cnt1+cnt2>k)puts("-1");
        else printf("%lld %lld\n",cnt1,cnt2);
    }
    return 0;
}
