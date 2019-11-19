#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int cnt[2][2] = {0};
        for(int k = 0; k < 2; k++){
            int n;
            scanf("%d", &n);
            for(int i = 1; i <= n; i++){
                int p;
                scanf("%d", &p);
                cnt[k][p % 2]++;
            }
        }
        printf("%lld\n", 1LL * cnt[0][0] * cnt[1][0] + 1LL * cnt[0][1] * cnt[1][1]);
    }
    return 0;
}