#include<bits/stdc++.h>
using namespace std;
#define maxn 100008
#define int long long
int t;
int n,m;
int p[maxn];
int q[maxn];
map<int,int> map1;
int ans=0;
signed main(){
    scanf("%lld",&t);
    while(t--){
        int ans=0;
        map1.clear();
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&p[i]),map1[p[i]&1]++;
        scanf("%lld",&m);
        for(int i=1;i<=m;i++)scanf("%lld",&q[i]),ans+=map1[(q[i]&1)];
        cout<<ans<<endl;
    }
    return 0;
}