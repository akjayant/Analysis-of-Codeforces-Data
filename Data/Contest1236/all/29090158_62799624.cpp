#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1000000007;

int mp[305][305];
int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int j=1;j<=n;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                mp[i][j]=++cnt;
            }
        }
        else{
            for(int i=n;i>=1;i--){
                mp[i][j]=++cnt;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            printf("%d ",mp[i][j]);
        }
        printf("%d\n",mp[i][n]);
    }
    return 0;
}
