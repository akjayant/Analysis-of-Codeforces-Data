#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <ctime>
#include <map>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const int mod=1e9+7;
int n,m;
ll f[maxn];
int main(){
    cin>>n>>m;
    f[0]=0;
    f[1]=f[2]=2;
    for(int i=3;i<maxn;i++) f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=2;i<maxn;i++) f[i]=(f[i]+f[i-1])%mod;
    ll ans=(2+f[n-1]+f[m-1])%mod;
    cout<<ans<<endl;
    return 0;
}
