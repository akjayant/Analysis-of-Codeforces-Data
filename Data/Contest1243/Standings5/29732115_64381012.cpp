#include<bits/stdc++.h>

using namespace std;
const int maxnn=1e4+7;
int a[maxnn];
int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int n;
        scanf("%d",&n);
        char s[maxnn];
        char t[maxnn];
        scanf("%s",s);
        scanf("%s",t);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
                a[cnt++]=i;
        }
        if(cnt==0)
        {
            printf("Yes\n");
        }
        else if(cnt!=2)
        {
            printf("No\n");
        }
        else
        {
            if(s[a[0]]==s[a[1]]&&t[a[0]]==t[a[1]])
            {
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}
