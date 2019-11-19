#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
long long A[N+10];

int main(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%I64d", A+i);
    sort(A+1, A+n+1);
    long long x = 0, y = 0;
    for (int i = 1; i <= n/2; ++i){
        x += A[i];
    }
    for (int i = n/2+1; i <= n; ++i){
        y += A[i];
    }
    printf("%I64d\n", x*x + y*y);
    return 0;
}