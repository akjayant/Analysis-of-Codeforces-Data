#include <stdio.h>
#include <iostream>
using namespace std;

int mainn()
{
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    int ans=0;
    for (int i=0;i<=100;++i)
    for (int j=0;j<=100;++j)
    {
        if (a>=i && b>=2*i+j && c>=2*j)
            if (ans<3*(i+j))
                ans= 3*(i+j);

    }
    printf("%d\n",ans);
}


int main()
{
    int t;scanf("%d",&t);
    while (t--) mainn();


}
