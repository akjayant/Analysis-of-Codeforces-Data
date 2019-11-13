#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=4e5+10;



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,ans=0;
        scanf("%d%d%d",&a,&b,&c);
        ans+=min(c/2*3,b*3);
        b-=min(c/2,b);
        ans+=min(a,b/2)*3;
        printf("%d\n",ans);
    }
    return 0;
}
