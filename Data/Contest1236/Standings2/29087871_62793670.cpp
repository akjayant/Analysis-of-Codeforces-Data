#include <bits/stdc++.h>
using namespace std;
const long long D=1e9+7;
int ans[301][301];
long long pow2(long long x,long long y){
    if(y==0)return 1;
    long long ret=pow2(x,y/2);
    ret=ret*ret%D;
    if(y%2==1)return ret*x%D;
    return ret;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int k=0;
    int i,j;
    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=n/2 ; j++){
            ans[i][j]=++k;
        }
    }
    for(i=1 ; i<=n ; i++)
    for(j=n/2+1 ; j<=(n+1)/2 ; j++)ans[i][j]=++k;
    for(i=n ; i>=1 ; i--){
        for(j=n ; j>(n+1)/2 ; j--){
            ans[i][j]=++k;
        }
    }
    for(i=1 ; i<=n  ; i++){
        for(j=1 ; j<=n ; j++)cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
