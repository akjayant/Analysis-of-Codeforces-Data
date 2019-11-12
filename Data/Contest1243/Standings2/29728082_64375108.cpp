#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e3 + 5, M = 3e5 + 5;

int a[N];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0 ; i < n ; ++i)
            scanf("%d", a + i);
        sort(a, a + n);
        reverse(a, a + n);
        int mx = INT_MIN;
        for(int i = 0 ; i < n ; ++i)
            mx = max(mx, min(a[i], i + 1));
        printf("%d\n", mx);
    }
}