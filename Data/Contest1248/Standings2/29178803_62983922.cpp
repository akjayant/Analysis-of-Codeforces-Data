#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000010;
const int mod=1000000007;
multiset<ll>s;
ll a[N];
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n,m,t;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],s.insert(a[i]);
    int tot=1;
    ll x=0,y=0;
    while(!s.empty()) {
        if(tot&1) {
            x+=*(--s.end());
            s.erase(--s.end());
        }else {
            y+=*(s.begin());
            s.erase(s.begin());
        }
        tot++;
    }
    printf("%lld\n",x*x+y*y);
    return 0;
}
