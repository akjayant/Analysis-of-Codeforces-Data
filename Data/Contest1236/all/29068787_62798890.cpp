#include <bits/stdc++.h>
#define lson root<<1
#define rson root<<1|1
using namespace std;
//priority_queue<int,vector<int>,greater<int> > q;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+7;
const int mod=1e9+7;
int ans[310][310];
int main()
{
    int n;
    scanf("%d",&n);
    int l=n*n;
    for(int i=1;i<=n;i++){
        if(i&1){
            for(int j=1;j<=n;j++){
                ans[j][i]=l--;
            }
        }
        else{
            for(int j=n;j>0;j--){
                ans[j][i]=l--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j!=1)printf(" ");
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
