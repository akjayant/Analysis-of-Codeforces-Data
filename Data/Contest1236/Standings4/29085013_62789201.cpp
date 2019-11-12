#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define llinf 8987654321987654321
#define inf 1987654321
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
int a, b, c;
int t;
int main()
{
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%d %d %d", &a, &b, &c);
        int ans=0;
        for(int j=0; j<=a&&j*2<=b; j++){
            ans=max(ans, j+min(b-2*j, c/2));
        }
        printf("%d\n", ans*3);
    }
}
