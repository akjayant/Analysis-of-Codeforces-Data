#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 3e5+100;
const db eps = 1e-6;


char str[200];
int ans[200];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        int a, b, c;
        scanf("%d%d%d%d", &n, &a, &b, &c);
        for(int i = 0; i < n+10; i++)ans[i] = 0;
        scanf("%s", str);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] == 'S')
            {
                if(a)
                {
                    cnt++;
                    ans[i] = 1;
                    a--;
                }
            }
            else if(str[i] == 'P')
            {
                if(c)
                {
                    cnt++;
                    ans[i] = 3;
                    c--;
                }
            }
            else if(str[i] == 'R')
            {
                if(b)
                {
                    cnt++;
                    ans[i] = 2;
                    b--;
                }
            }
        }
        if(cnt>=(n+1)/2)
        {
            for(int i = 0; i < n; i++)
            {
                if(ans[i]==0)
                {
                    if(a)
                    {
                        a--;
                        ans[i] = 1;
                    }
                    else if(b)
                    {
                        b--;
                        ans[i] = 2;
                    }
                    else if(c)
                    {
                        c--;
                        ans[i] = 3;
                    }
                }
            }
            printf("YES\n");
            for(int i = 0; i < n; i++)
            {
                if(ans[i] ==1)
                {
                    printf("R");
                }
                else if(ans[i]==2)
                {
                    printf("P");
                }
                else if(ans[i] == 3)
                {
                    printf("S");
                }
            }
            printf("\n");
        }
        else
        {
            printf("NO\n");
        }
    }




    return 0;
}
