#include<bits/stdc++.h>
#define ll long long
#define zp push_back
#define zm make_pair
#define zl lower_bound
#define z1 first
#define z2 second
using namespace std;
int z(){int z;scanf("%d",&z);return z;}
ll Z(){ll Z;scanf("%I64d",&Z);return Z;}

const int M = 5e5+5;
ll n,p,w,d;
ll x, y;
void cal(){
    if(p>n*w){
        puts("-1");return;
    }
    if(p%d==0 && p/d<=n){
        cout<<0 <<' '<<p/d<<' '<<(n-p/d)<<endl;
        return;
    }
    if(p%w==0 && p/w<=n){
        cout<<p/w <<' '<<0<<' '<<(n-p/w)<<endl;
        return;
    }
    ll high = p / w;
    ll low = high - d;
    if(low<0)low = 0;
    for(ll i = high;i>=low;i--){
        ll rem = p - i * w;
        if(rem % d == 0 && rem/d + i<=n){
        cout<<i <<' '<<rem/d<<' '<<(n-i-rem/d)<<endl;
            return;
        }
    }
    printf("-1\n");
}

int main(){
    cin>>n>>p>>w>>d;
    cal();
}
