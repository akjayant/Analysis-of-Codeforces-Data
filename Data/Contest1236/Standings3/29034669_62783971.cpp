#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
     int T;
     scanf("%d",&T);
     while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        if(b*2>c){
            ans+=c/2;
            b-=c/2;
            if(a*2>b){
                ans+=b/2;
            }else{
                ans+=a;
            }
        }else{
            ans+=b;
        }
        printf("%d\n",ans*3);
     }
}