#include<bits/stdc++.h>
using namespace std;
int ara[1003];
int main()
{
    int ts, n;
    scanf("%d", &ts);
    while(ts--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", &ara[i]);
        int res= 0;
        for(int i=n; i>=1; i--)
        {
            int cnt= 0;
            for(int j=0; j<n; j++)
                if(ara[j]>=i)cnt++;
            if(cnt>=i)
            {
                res= i;
                break;
            }
        }printf("%d\n", res);
    }

    return 0;
}
