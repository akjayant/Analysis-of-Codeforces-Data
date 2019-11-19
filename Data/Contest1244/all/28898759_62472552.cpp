#include <bits/stdc++.h>
using namespace std;

long long n,p,w,d;

long long gcd(long long a,long long b){
    return a%b?gcd(b,a%b):b;
}

int main(){
    scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
    if(n*w<p){
        printf("-1");
        return 0;
    }
    long long g=gcd(w,d);
    if(p%g>0){
        printf("-1");
        return 0;
    }
    p/=g;
    w/=g;
    d/=g;
    long long re=p%w;
    bool hasre=0;
    long long mind=0;
    for(long long i=0;i<w;i++){
        if(i*d%w==re){
            mind=i;
            hasre=1;
            break;
        }
    }
    if(hasre==0){
        printf("-1");
        return 0;
    }
    if(mind*d>p){
        printf("-1");
        return 0;
    }
    long long x=0,y=mind;
    x=(p-y*d)/w;
    if(x+y>n){
        printf("-1");return 0;
    }
    printf("%lld %lld %lld\n",x,y,n-x-y);
    return 0;
}
