/*Program from Luvwgyx*/
#include<bits/stdc++.h>
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
    int n=read(),p=read(),w=read(),d=read();
    int gcd=__gcd(w,d);
    if(p%gcd){puts("-1");return 0;}
    p/=gcd;w/=gcd;d/=gcd;
    //printf("%lld %lld %lld\n",p,w,d);
    int ans1=0;bool flag=0;
    while(ans1<=n){
        if(w*ans1>p){flag=1;break;}
        if(!((p-w*ans1)%d))break;
        ans1++;
    }//write(ans1);
    if(flag){puts("-1");return 0;}
    int ans2=(p-w*ans1)/d;
    if(d<w){int tmp=ans2/w;ans1+=d*tmp;ans2-=w*tmp;}
    if(ans1+ans2>n){puts("-1");return 0;}
    printf("%lld %lld %lld\n",ans1,ans2,n-ans1-ans2);
    return 0;
}
