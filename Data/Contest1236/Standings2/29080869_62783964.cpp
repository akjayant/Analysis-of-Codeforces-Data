#include <bits/stdc++.h>
#define maxn 300010
using namespace std;
typedef long long ll;
int a[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int ans = min(y,z/2);
        y -= ans;
        ans += min(x,y/2);
        printf("%d\n",ans*3);
    }
}
