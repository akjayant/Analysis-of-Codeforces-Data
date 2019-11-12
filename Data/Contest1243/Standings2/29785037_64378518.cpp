#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N],n;
int main()
{
    int t;
    scanf("%d",&t);
    for(int tst=1;tst<=t;tst++){
        int ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1,greater<int>());
        for(int i=1;i<=n;i++){
            int curr=min(i,a[i]);
            ans=max(ans,curr);
        }
        printf("%d\n",ans);
    }
    return 0;
}
