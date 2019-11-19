#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
const int N=5e5+10, base=1e9+123;
long long n,p,w,d;
bool vis[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>p>>w>>d;
    if(p%__gcd(d,w)!=0) return cout<<-1<<'\n',0;
    long long other=p%w;
    p-=other;
    while(other%d){
        if(vis[other%d]) break;
        vis[other%d]=1;
        other+=w;
        p-=w;
    }
    if(p<0||p%w||other%d) return cout<<-1<<'\n',0;
    long long cur=p/w+other/d;
    if(cur<=n){
        long long x=p/w, y=other/d, z=n-cur;
        cout<<x<<' '<<y<<' '<<z<<'\n';
    }
    else cout<<-1<<'\n';
    return 0;
}
