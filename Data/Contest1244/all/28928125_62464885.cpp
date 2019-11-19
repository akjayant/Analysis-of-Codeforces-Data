#include<bits/stdc++.h>
#define ll long long
#define S second
#define F first

using namespace std;

const int N = 1e6+5;

int main()
{
    int t, a, b, c, d, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        a = (a + c - 1) / c;
        b = (b + d - 1) / d;
        if(a + b <= k)
        {
            printf("%d %d\n", a, b);
        }
        else puts("-1");
    }
}
