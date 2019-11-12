#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

char s[N],t[N];

int main() {
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int n;
        scanf("%d%s%s",&n,s,t);
        int cnt=0,x,y;
        for(int i=0;i<n;++i)
        {
            if(s[i]!=t[i])
            {
                ++cnt;
                if(cnt==1)
                    x=i;
                else y=i;
            }
        }
        if(cnt==0)
            puts("Yes");
        else if(cnt==1||cnt>=3)
            puts("No");
        else if(s[x]==s[y]&&t[x]==t[y])
            puts("Yes");
        else puts("No");
    }
    return 0;
}
