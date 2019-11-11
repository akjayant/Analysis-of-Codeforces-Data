#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int TC, A, B;

int main()
{
    int i, j;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d", &A, &B);
        if(__gcd(A, B)==1) printf("Finite\n");
        else printf("Infinite\n");
    }
}
