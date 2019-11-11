#include<bits/stdc++.h>
using namespace std;
//A
int q,a,b;
int gcd(int a,int b)
{
    if(b>a)
        return gcd(b,a);
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        if(gcd(a,b)==1)
            printf("Finite\n");
        else
            printf("Infinite\n");
    }
    
}

//E
