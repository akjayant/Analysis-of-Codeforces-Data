//in his name
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int mod=1e9+7;
int f[100005];
int32_t main(){
    int n,m;
    cin>>n>>m;
    f[1]=1;
    f[2]=2;
    f[3]=3;
    for(int i=4;i<=max(n,m);i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    cout<<(2ll*(f[n]+f[m]-1))%mod<<endl;
}
