#include <bits/stdc++.h>
using namespace std;
int T;
int a,b,c,d,k;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c>>d>>k;
        bool flag=0;
        for(int i=1;i<=k;++i)
        {
            if(c*i>=a&&d*(k-i)>=b)
            {
                printf("%d %d\n",i,k-i);flag=1;
                break;
            }
        }
        if(!flag)puts("-1");
    }
    return 0;
}
