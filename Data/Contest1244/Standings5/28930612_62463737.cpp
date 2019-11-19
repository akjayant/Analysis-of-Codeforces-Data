#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
     int T;
     scanf("%d",&T);
     while(T--){
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int x1=a/c;
        if(a%c!=0){
            x1++;
        }
        int x2=b/d;
        if(b%d!=0){
            x2++;
        }
        if(x1+x2>k){
            printf("-1\n");
        }else{
            printf("%d %d\n",x1,x2);
        }
     }
}