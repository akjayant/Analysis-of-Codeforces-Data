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
signed main(){
    int t=read();
    while(t--){
        int n=read();
        int s1=0,s2=0,c1=0,c2=0;
        for(int i=1;i<=n;i++){
            int p=read();
            if(p&1)s1++;
            else s2++;
        }
        int m=read();
        for(int i=1;i<=m;i++){
            int q=read();
            if(q&1)c1++;
            else c2++;
        }
        printf("%lld\n",s1*c1+s2*c2);
    }
    return 0;
}
