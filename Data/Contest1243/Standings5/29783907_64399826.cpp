#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
    LL n, mind = -1, cnt = 0;
    scanf("%lld", &n);
    for(LL d = 2, upper = sqrt(n)+1;d <= upper;d++)
    {
        if(n % d == 0)
        {
            cnt++;
            if(mind == -1) mind = d;
            while(n % d == 0) n /= d;
        }
    }
    if(n != 1)
    {
        cnt++;
        if(mind == -1) mind = n;
    }
    printf("%lld", cnt == 1 ? mind : 1);
    return 0;
}
