#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int ans[310][310];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int base=1;
    for(int i=1;i<=n;i++){
        int fir=base;
        base+=n;
        if(i&1){
            for(int j=1;j<=n;j++){
                ans[j][i]=fir; fir++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                ans[j][i]=fir; fir++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
