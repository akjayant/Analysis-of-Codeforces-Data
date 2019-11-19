#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 7;

int t, n, m;
int a, b,c,d,x;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        a = b = c = d = 0;
        scanf("%d", &n);
        for (int i = 0; i < n;i++)
        {
            scanf("%d", &x);
            if(x % 2 == 0)
            {
                a++;
            }
            else
            {
                b++;
            }
            
        }
        scanf("%d", &m);
        for (int i = 0; i < m;i++)
        {
            scanf("%d", &x);
            if(x % 2 == 0)
            {
                c++;
            }
            else
            {
                d++;
            }
            
        }
        ll sum = 1ll * a * c + 1ll * b * d;
        printf("%lld\n", sum);
    }
    return 0;
}