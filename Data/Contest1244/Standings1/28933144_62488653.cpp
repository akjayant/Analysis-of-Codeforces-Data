#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;
ll n, p, w, d;
void exgcd(ll a,ll b, ll& d,ll &x, ll& y){
    if(!b){d=a; x=1; y=0;}
    else{exgcd(b,a%b,d,y,x); y-=x*(a/b);}
}
ll getexgcd(ll a, ll b, ll c){
    ll d, x, y; exgcd(a,b,d,x,y);
    if(c%d!=0) return -1;  b=abs(b/d);
    return (x%b+b)*(c/d%b)%b;
}
int main(){
    scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
    ll y=getexgcd(d,w,p);
    if(y==-1||y>n) printf("-1\n");
    else{
        ll t=p-d*y;
        if(t<0||t%w!=0) printf("-1\n");
        else{
            ll x=t/w;
            ll z=n-x-y;
            if(z<0) printf("-1\n");
            else printf("%lld %lld %lld\n",x,y,z);
        }
    }
    return 0;
}
