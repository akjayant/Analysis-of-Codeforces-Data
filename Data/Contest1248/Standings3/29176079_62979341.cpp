#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n,m,x;
        ll sum0n,sum1n,sum0m,sum1m;
        sum0m=sum0n=sum1m=sum1n=0;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>x;
            if (x&1) sum0n++;
            else sum1n++;
        }
        cin>>m;
        for (int i=1;i<=m;i++){
            cin>>x;
            if (x&1) sum0m++;
            else sum1m++;
        }
        ll ans=sum0m*sum0n+sum1n*sum1m;
        cout<<ans<<endl;
    }
    return 0;
}