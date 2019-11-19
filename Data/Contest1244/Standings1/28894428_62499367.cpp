/*Program from Luvwgyx*/
#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int inf=1e18;
const int maxn=1e5+10;
int n,K,a[maxn];
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
    n=read();K=read();bool flag=0;
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);int l=1,r=n,lsize=1,rsize=1;
    while(l<r){
        if(lsize<rsize){
            int tmp=a[l+1]-a[l];
            if(tmp*lsize<=K){K-=tmp*lsize;l++;lsize++;}
            else{flag=1;break;}
        }else{
            int tmp=a[r]-a[r-1];
            if(tmp*rsize<=K){K-=tmp*rsize;r--;rsize++;}
            else{flag=1;break;}
        }
    }int now=K/lsize;
    if(!flag)puts("0");else write(a[r]-a[l]-now);
    return 0;
}
