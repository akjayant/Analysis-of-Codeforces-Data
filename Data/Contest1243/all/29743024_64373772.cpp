#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=2e5+10;

int a[MAXN];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1,greater<int>());
        int ans=0;
        for(int i=1;i<=n;i++)
            if(a[i]>=i)ans++;
        else break;
        printf("%d\n",ans);
    }
    return 0;
}
