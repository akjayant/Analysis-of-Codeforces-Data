#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
signed main(){
    int t=read();
    while(t--){
        int t1=0,t2=0,t3=0,t4=0;
        int n=read();
        for(int i=1;i<=n;i++){
            int x=read();
            if(x%2==0) ++t1;
        }t2=n-t1;int m=read();
        for(int i=1;i<=m;i++){
            int x=read();
            if(x%2==0) ++t3;
        }t4=m-t3;
        printf("%lld\n",t1*t3+t2*t4);
    }
    return 0;
}
