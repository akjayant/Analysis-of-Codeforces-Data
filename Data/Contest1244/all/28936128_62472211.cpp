#include <bits/stdc++.h>
using namespace std;

int n;
char s[1010];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&n,s);
        int ma=0;
        for(int i=0;i<n;i++)
            if(s[i]=='1')
            {
                ma=max(ma,i+1);
                ma=max(ma,n-i);
            }
        printf("%d\n",max(2*ma,n));
    }
}