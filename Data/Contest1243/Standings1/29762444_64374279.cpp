#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[10005];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,min(a[i],n-i+1));
        }
        printf("%d\n",ans);
    }
    return 0;
}
