
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,t,i,j,k,a,b,c,x,y,z;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        scanf("%d%d",&a,&b);
        c=__gcd(a,b);
        if(c==1)
        {
            printf("Finite\n");
        }
        else{
            printf("Infinite\n");
        }
    }
}
