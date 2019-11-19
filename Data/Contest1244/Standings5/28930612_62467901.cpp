#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1005];
int main()
{
     int T;
     scanf("%d",&T);
     while(T--){
        int n;
        scanf("%d",&n);
        scanf("%s",a+1);
        int ans=n;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]=='1'){
                cnt++;
                ans=max(ans,2*i);
                ans=max(ans,2*(n-i+1));
            }
        }
        ans=max(ans,n+cnt);
        printf("%d\n",ans);
     }
}