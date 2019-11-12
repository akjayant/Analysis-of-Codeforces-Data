#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void Run()
{
    int n, i, j, k;
    vector<int> a, b;
    scanf("%d", &n);
    a.resize(n + 1);
    b.resize(n + 1);
    for(i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    a[0] = 0;
    sort(a.begin(), a.end());
    for(i = 1; i <= n; ++i)
        b[i] = a[n + 1 - i];
    for(k = 1; k <= n && b[k] >= k; ++k)
    {}
    printf("%d\n", k - 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        Run();
    return 0;
}
