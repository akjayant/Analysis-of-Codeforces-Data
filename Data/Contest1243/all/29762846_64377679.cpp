#include<bits/stdc++.h>
using namespace std;
int n,a[10010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        int ans=1,mh=a[1];
        for(int i=1;i<=n;i++){
            if(a[i]>=n-i+1){
                ans=max(ans,n-i+1);
            }
        }
        printf("%d\n",ans);
    }
}
