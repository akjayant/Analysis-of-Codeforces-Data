#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
int n,a[N];
int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
signed main(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);int hd=1,ed=n;
    int ans1=0,ans2=0;
    while(hd<ed){
        ans1+=a[hd];
        ans2+=a[ed];
        ++hd;--ed;
    }if(hd==ed) ans2+=a[hd];
    printf("%lld\n",ans1*ans1+ans2*ans2);
    return 0;
}
