#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

int main()
{
    int T,a,b,c,d,N,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&N);
        x=a/c+(a%c>0);
        y=b/d+(b%d>0);
        if(x+y<=N) printf("%d %d\n",x,y);
        else printf("-1\n");
    }
    return 0;
}
