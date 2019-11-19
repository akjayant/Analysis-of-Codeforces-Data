#include <bits\stdc++.h>
using namespace std;
int main(){
    int t, a, b, c, d, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if((a+c-1)/c+(b+d-1)/d<=k)
            printf("%d %d\n", (a + c - 1) / c, (b + d - 1) / d);
            else
                printf("-1\n");

    }
    return 0;
}
