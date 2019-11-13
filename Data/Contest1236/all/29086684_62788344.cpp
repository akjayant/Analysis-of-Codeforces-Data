#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    int a,b,c;
    int res;
    scanf("%d",&T);
    while(T--){
            res=0;
    scanf("%d %d %d",&a,&b,&c);
    c=c/2;
    if(b<=c){
       res=3*b;
       printf("%d\n",res);
       continue;
    }
    else {
       b-=c;
       res=3*c;
    }
    b/=2;
    if(a<=b){
        res+=3*a;
        printf("%d\n",res);
        continue;
    }
    else {
        res+=3*b;

    }
    printf("%d\n",res);
    }
}
