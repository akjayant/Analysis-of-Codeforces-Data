#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10, mod=1e9+7;
int t, n, arr[N];

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        int ans=1, mn=arr[n-1];
        for(int i=n-1;i>=0;i--){
            mn=min(mn, arr[i]);
            int cur=min(n-i, mn);
            ans=max(ans, cur);
        }
        printf("%d\n",ans);
    }
    return 0;
}
