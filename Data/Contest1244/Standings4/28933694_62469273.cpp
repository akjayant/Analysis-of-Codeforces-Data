#include<bits/stdc++.h>

using namespace std;

int tc, n;
char s[1005];

int main()
{
    for(scanf("%d",&tc) ; tc>0 ; tc--){
        scanf("%d",&n);
        scanf("%s",&s[1]);
        int ans=n;
        for(int i=1 ; i<=n ; i++){
            if(s[i]=='1'){
                int v=max(i,n-i+1);
                ans=max(ans,v*2);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
