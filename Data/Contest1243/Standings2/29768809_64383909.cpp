#include <bits/stdc++.h>
using namespace std;
int t,n;
char a[10005];
char b[10005];

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        scanf("%s",a);
        scanf("%s",b);
        vector<int> v;
        for (int i=0;i<n;i++)
        {
            if (a[i]!=b[i]) v.push_back(i);
        }
        if (v.size()>2) printf("No\n");
        else if (v.size()==2)
        {
            if (a[v[0]]==a[v[1]] && b[v[0]]==b[v[1]]) printf("Yes\n");
            else printf("No\n");
        }
        else if (v.size()==1) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}

