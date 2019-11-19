#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,p,d,w;
int main()
{
    cin>>n>>p>>w>>d;
    for(LL y=0;y<=w;y++){
        if((y*d)%w == (p%w)){
            LL tmp=p-y*d;
            if(tmp>=0){
                LL x=tmp/w;
                if(x+y<=n){
                    cout<<x<<" "<<y<<" "<<n-x-y;
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}
//a*x=1 (mod m)
