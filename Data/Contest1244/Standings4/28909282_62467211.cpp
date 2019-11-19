#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <utility>

using namespace std;
char all[1005];
int main()
{
    int T,ans=0,N,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %s",&N,all);
        ans=N;
        for(i=0;i<N;i++)
        {
            if(all[i]=='1')
            {
                ans=max(ans,2*(i+1));
                ans=max(ans,2*(N-i));
            }
        }
        printf("%d\n",ans);

    }

    return 0;

}
