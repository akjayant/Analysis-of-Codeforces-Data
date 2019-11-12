#include<bits/stdc++.h>
using namespace std;
int ans[305][305];
int main() {
    int n;
    cin>>n;
    int now=n*n;
    for(int i=1;i<=n;i++) {
        if(i&1) {
            for(int j=n;j>=1;j--)
                ans[j][i]=now--;
        } else {
            for(int j=1;j<=n;j++)
                ans[j][i]=now--;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<ans[i][j]<<" \n"[j==n];
        }
    }
    return 0;
}
