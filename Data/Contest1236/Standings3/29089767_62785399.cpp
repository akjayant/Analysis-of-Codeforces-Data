#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int ans = 0;

        for(int i = 0; i <= a; i++)
        {
            for(int j = 0; j <= b; j++)
            {
                if(2*i+j <= b && 2*j <= c) ans = max(ans, i+2*i+j+2*j);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
