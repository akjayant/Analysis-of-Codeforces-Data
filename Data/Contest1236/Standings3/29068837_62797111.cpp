#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6+50;
const int MOD = 1e9+7;
int a[305][305];
int main(){
    int n;
    cin>>n;
    int tmp = n*n;
    for(int k=1;k<=n;k++){
        if(k&1){
            for(int i=1;i<=n;i++)
                a[i][k]=tmp--;
        }
        else{
            for(int i=n;i>=1;i--)
                a[i][k]=tmp--;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<(j==n ? '\n':' ');
    return 0;
}
