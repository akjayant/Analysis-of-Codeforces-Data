#include<bits/stdc++.h>
using namespace std;

int n,a[305][305];

int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (i&1) a[i][j] = (i-1)*n+j;
            else a[i][j] = (i-1)*n+n+1-j;
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }

    return 0;
}
