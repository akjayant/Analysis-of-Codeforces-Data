#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
ll mod=1e9+7;
long long pwr(long long x, long long e){
    if(e==0)
        return 1;
    long long tmp=pwr(x,e/2);
    tmp=(tmp*tmp)%mod;
    if(e%2)
        tmp=(tmp*x)%mod;
    return tmp;
}
int main(){
    ll n, m;
    while(cin>>n>>m){
        ll ans=0;
        ans=pwr(pwr(2, m)-1, n);
        cout<<ans<<endl;
    }
  return 0;
}


