#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        int ans=0;
        scanf("%d%d%d",&a,&b,&c);
        int tmp=0;
        int x = min(b,c/2);
        tmp+=x*3;
        int y = min(a,(b-x)/2);
        tmp+=y*3;
        ans = max(ans,tmp);
        tmp=0;
        x = min(a,b/2);
        tmp+=x*3;
        y = min(b-x*2,c/2);
        tmp+=y*3;
        ans = max(ans,tmp);
        printf("%d\n",ans);
    }
    return 0;
}
