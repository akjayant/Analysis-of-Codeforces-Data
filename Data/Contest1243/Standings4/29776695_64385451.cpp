//μ's forever
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int q,n;
string s1,s2;
int main()
{
    cin>>q;
    while(q--)
    {
        cin>>n>>s1>>s2;
        int x=0,y=0,cnt=0;
        for(register int i=0;i<n;++i)
        {
            if(s1[i]!=s2[i])
            {
                ++cnt;
                if(cnt==3)
                {
                    puts("No");
                    break;
                }
                if(x==y)
                    x=i;
                else
                    y=i;
            }
        }
        if(cnt==3)
            continue;
        if(cnt==1)
            puts("No");
        else if(s1[x]==s1[y]&&s2[y]==s2[x])
            puts("Yes");
        else
            puts("No");
    }
	return 0;
}
