#include<bits/stdc++.h>
using namespace std;

int a[444][444];

int main() {
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int t=(i-1)*n;
        if(i&1) for(int j=1;j<=n;j++) a[j][i]=++t;
        else for(int j=n;j;j--) a[j][i]=++t;
    }
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++) printf("%d ",a[i][j]);
    return 0;
}
