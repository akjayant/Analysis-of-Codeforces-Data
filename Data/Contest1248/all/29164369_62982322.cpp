#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int main(){
    int test;
    test = 1;
    while(test--){
        int n, a[N];
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        long long p = 0, b = 0;
        for(int i = 1; i <= n / 2; i++){
            p += a[i];
        }
        for(int i = n / 2 + 1; i <= n; i++){
            b += a[i];
        }
        printf("%lld\n", p * p + b * b);
    }
    return 0;
}