#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>

#define fuck(x) cerr<<#x<<" = "<<x<<endl;
#define debug(a, x) cerr<<#a<<"["<<x<<"] = "<<a[x]<<endl;
#define lson l,mid,ls
#define rson mid+1,r,rs
#define ls (rt<<1)
#define rs ((rt<<1)+1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int loveisblue = 486;
const int maxn = 200086;
const int maxm = 1200086;
const int inf = 0x3f3f3f3f;
const ll Inf = 999999999999999999;
const int mod = 1000000007;
const double eps = 1e-6;
const double pi = acos(-1);

ll x=-1,y=-1,z=-1;
ll n,p,d,w;
bool solve(ll m){

    if(m<0||m>n){return false;}
//    fuck(m)
    ll rem = p - w*m;
    if(rem%d!=0){
        return false;
    }

    ll yy = rem/d;
    if(yy<0||m+yy>n){
        return false;
    }

    x=m;
    y=yy;
    z = n-x-y;
    return true;

}

int main() {
    ios::sync_with_stdio(true);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif


    scanf("%lld%lld%lld%lld",&n,&p,&w,&d);


    ll mn = p/w;
//    fuck(mn)
    for(ll i = mn-200000;i<=mn+200000;i++){
        if(solve(i)){
            break;
        }
    }
    if(x==-1){
        printf("-1\n");
    }
    else printf("%lld %lld %lld\n",x,y,z);

    return 0;
}
