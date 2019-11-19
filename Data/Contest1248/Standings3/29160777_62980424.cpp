#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MA=1e5+5;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll num1=0,num2=0,num3=0,num4=0;
        int x,n,m;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&x);
            if(x%2==1)num1++;
            else num2++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;++i){
            scanf("%d",&x);
            if(x%2==1)num3++;
            else num4++;
        }
        printf("%lld\n",(num1*num3)+(num2*num4));
    }
    return 0;
}
