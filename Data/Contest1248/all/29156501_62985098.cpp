#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[100005];

int main() {
    int n;
    LL sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) 
        scanf("%d", &a[i]), sum += a[i];
    sort(a,a+n);
    LL s1 = 0, s2 = 0;
    for(int i = 0; i < n/2; ++i)
        s1 += a[i];
    s2 = sum - s1;
    printf("%lld\n", s1*s1 + s2*s2);
    return 0;
}