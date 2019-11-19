#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    scanf("%d",&tc);
    for (int t = 0; t < tc; t++){
        int n;
        scanf("%d",&n);
        char a[n];
        int x = -1, y = -1;
        for (int i = 0; i < n; i++){
            scanf(" %c",&a[i]);
            if (a[i] == '1'){
                y = i;
                if (x == -1) x = i;
            }
        }
        if (x == -1) x = n;
        int ans = max(n,max(2*(n-x),2*(y+1)));
        printf("%d\n",ans);
    }
}
