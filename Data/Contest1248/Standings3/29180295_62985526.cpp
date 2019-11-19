#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 7;

int n;
ll a[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    ll sum = 0, sum1 = 0;
    for (int i = 0; i < n;i++)
    {
        if(i < n / 2)
        {
            sum += a[i];
        }
        else
        {
            /* code */
            sum1 += a[i];
        }
        
    }

    printf("%lld\n", sum * sum + sum1 * sum1);
    return 0;
}