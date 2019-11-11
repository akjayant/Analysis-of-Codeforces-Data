#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    return x*f;
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
signed main(){
    int t=read();
    while(t--){
        int a=read(),b=read();
        puts(gcd(a,b)==1?"Finite":"Infinite");
    }
    return 0;
}
