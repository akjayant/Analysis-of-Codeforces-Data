#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ts;
    cin>>ts;
    while(ts--){
    int a, b, c, d, e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    int x=a/c+((a%c)!=0);
    int y=b/d+((b%d)>0);
   // cout<<y<<" "<<(b/d)<<" "<<b<<" "<<d<<endl;
   // cout<<endl;
    if(e<(x+y))
    {
       printf("-1\n");
    }
    else{
       printf("%d %d\n",x,y);
    }
    }
}
