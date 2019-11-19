/*jai mata di
let's rock*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d,k;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        int val1=0,val2=0;
        val1=a/c;
        if(a%c) val1++;
        val2=b/d;
        if(b%d) val2++;
        if(val1+val2>k) printf("-1\n");
        else printf("%d %d\n",val1,val2);
    }
    return 0;
}
