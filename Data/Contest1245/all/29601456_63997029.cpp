#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,a,b,g;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        g=__gcd(a,b);
        if(g==1)
            puts("Finite");
        else
            puts("Infinite");
    }

    return 0;
}
