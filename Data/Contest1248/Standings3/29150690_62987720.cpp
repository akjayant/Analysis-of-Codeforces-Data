#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    return x*f;
}
const int N=1e5+28;
int n,a[N];
signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    int tmp1=0,tmp2=0;
    for(int i=1;i<=n/2;i++){
        tmp1+=a[i];
    }
    for(int i=n/2+1;i<=n;i++){
        tmp2+=a[i];
    }
    printf("%lld",tmp1*tmp1+tmp2*tmp2);
    return 0;
}
/*
3
1 2 3
*/
