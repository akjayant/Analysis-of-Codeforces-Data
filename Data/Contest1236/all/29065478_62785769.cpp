#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int TC;
int A, B, C;

int main()
{
    int i, j;

    scanf("%d", &TC);
    while(TC--)
    {

        scanf("%d%d%d", &A, &B, &C);
        int ans=0;
        for(i=0; i<=100; i++) for(j=0; j<=100; j++)
        {
            if(i<=A && 2*i+j<=B && 2*j<=C) ans=max(ans, 3*(i+j));
        }
        printf("%d\n", ans);
    }
}