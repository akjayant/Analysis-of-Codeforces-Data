#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int maxn = 1e6+7;
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;
ll f[maxn];
int main(){
    f[0]=1;
    f[1]=1;
    for(int i=2;i<maxn;i++) f[i]=(f[i-1]+f[i-2])%mod;
    int n,m;
    cin>>n>>m;
   // cout<<f[m]<<' '<<f[n]<<endl;
    cout<<2*(f[m]+f[n]-1+mod)%mod<<endl;
}
