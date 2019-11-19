#include<iostream>
#include<cstdio>
typedef long long ll;
ll gcd(ll a,ll b,ll &x,ll &y) {
    ll res=a;
    if(!b) x=1,y=0;
    else {
        res=gcd(b,a%b,y,x);
        y-=a/b*x;
    }
    return res;
}
int main() {
    ll n,p,d,w,x,y;
    scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
    ll g=gcd(w,d,x,y);
    if(p%g) return !printf("-1");
    p/=g;
    y=(y%(w/g)+w/g)*(p%(w/g))%(w/g);
    x=(p*g-d*y)/w;
    if(x<0||x+y>n) return !printf("-1");
    printf("%lld %lld %lld",x,y,n-x-y);
    return 0;
}
