#include<bits/stdc++.h>
#define see(x) cout<<#x<<" = "<<x<<endl

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll ans[1000][1000];
int main(){
    ll n;
    cin>>n;
    ll cnt=0;
    bool flag=1;
    for(int i=1;i<=n;i++){
            if(i%2)
        for(int j=1;j<=n;j++){
            ans[j][i]=++cnt;
        }
        else
        for(int j=n;j>=1;j--){
            ans[j][i]=++cnt;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld",ans[i][j]);
            if(j==n)
                printf("\n");
            else
                printf(" ");
        }
    }
return 0;
}
