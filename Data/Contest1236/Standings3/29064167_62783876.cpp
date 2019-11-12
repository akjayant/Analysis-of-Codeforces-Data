#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int ans = 0;
        for (int j = 0; j <= min(a,b/2); j++){
            int cur = j*3;
            cur += min(b-j*2,c/2)*3;
            ans = max(cur,ans);
        }
        printf("%d\n",ans);
    }
}
