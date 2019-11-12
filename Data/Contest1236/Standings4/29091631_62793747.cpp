#include<bits/stdc++.h>
using namespace std;
mt19937 rng(0);
typedef long long ll;
const ll mod=1e9+7;
int ans[500][500];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j<n/2)ans[i][j]=n*j+i+1;
            else ans[i][j]=n*j+n-i;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)printf("%d ",ans[i][j]);
        printf("\n");
    }
}