#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e5+10;
const ll mod=1e9+7;
vector<int>rec[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                rec[j].push_back((i-1)*n+j);
            }
        }else{
            for(int j=n;j>=1;j--){
                rec[j].push_back((i-1)*n+n-j+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
       for(int j=0;j<n;j++){
        printf("%d ",rec[i][j]);
       }
       printf("\n");
    }
    return 0;
}
