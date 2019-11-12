#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int a[maxn];
char s[maxn];
int main()
{
    int n;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n,greater<int>());
        int ans=1;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,min(i+1,a[i]));
        }
        printf("%d\n",ans);
    }


    return 0;
}