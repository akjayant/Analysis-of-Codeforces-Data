#include <cstdio>
#include <iostream>
using namespace std;
const int P=1e9+7;
int F[100005];
int main()
{
    int n,m;
    int a=2,b=4,c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<m;i++)
    {
        c=(a+b) % P;
        a=b;
        b=c;
    }
 //   printf("%d\n",a);
    int pre=a;
    a=2,b=4;
    for(int i=1;i<n;i++)
    {
        c=(a+b) % P;
        a=b;
        b=c;
    }
    printf("%d\n",(pre+a-2) % P);
    return 0;
}