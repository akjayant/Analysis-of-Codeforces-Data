#include<bits/stdc++.h>
using namespace std;
char ch[10005],s[10005];
vector < int > vec;

int main()
{
    int test,t,i,j,k,a,b,c,x,y,z,n;

    cin>>test;
    for(t=1;t<=test;t++)
    {
        scanf("%d%s%s",&n, ch, s);
        for(i=0;i<n;i++)
        {
            if(ch[i]!=s[i])
                vec.push_back(i);
        }
        z=vec.size();
        if(z==0||z==2)
        {
            if(z==2)
            {
                x=vec[0];
                y=vec[1];
                if(ch[x]==ch[y] && s[x]==s[y])
                {
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }

            }
            else{
                printf("YES\n");
            }
        }
        else{
            printf("NO\n");
        }
        vec.clear();
    }

}
