#include <bits/stdc++.h>
using namespace std;
int n;
#define ll long long
ll J1,O1,J2,O2;

int m;
int main()
{
    int T;cin>>T;
    while(T--)
    {
        J1=O1=J2=O2=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            int x;scanf("%d",&x);
            if(x&1)J1++;
            else O1++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;++i)
        {
            int x;scanf("%d",&x);
            if(x&1)J2++;
            else O2++;
        }
        printf("%lld\n",J1*J2+O1*O2);
    }
    return 0;
}
