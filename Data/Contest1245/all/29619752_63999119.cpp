#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9 + 7;
#define afdafafafdafaf y1;
int ar[maxn], n, m, k;

int main()
{
    int t;scanf("%d", &t);
    while(t--){
        int a,b;
        scanf("%d%d", &a, &b);
        if(__gcd(a, b) != 1)printf("Infinite\n");
        else printf("Finite\n");
    }

    return 0;
}
