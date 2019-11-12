#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> ans[310];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n*n;i++)
    {
        if (((i-1)/n)&1) ans[n-(i-1)%n].push_back(i);
        else ans[(i-1)%n+1].push_back(i);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j:ans[i])
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    getchar(); getchar();
    return 0;
}