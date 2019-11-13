#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,c;
int ans;

int main()
{
    int T;cin>>T;
    while(T--)
    {
        cin>>a>>b>>c;
        ans=0;
        while(b>=1&&c>1)
        {
            ans+=3;
            c-=2;
            b--;
        }
        while(b>1&&a>=1)
        {
            ans+=3;
            b-=2;
            a--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
