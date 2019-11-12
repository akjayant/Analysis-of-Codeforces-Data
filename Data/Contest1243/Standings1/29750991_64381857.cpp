#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
char s[N],t[N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        vector<int> dif;
        scanf("%s",s+1);
        scanf("%s",t+1);
        for(int i=1; i<=n; ++i)
        {
            if(s[i]!=t[i])
            {
                dif.push_back(i);
            }
        }
        if(dif.size()==1||dif.size()>2)
            printf("No\n");
        else if(dif.size()==0)
            printf("Yes\n");
        else if(s[dif[0]]==s[dif[1]]&&t[dif[0]]==t[dif[1]])
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
}
