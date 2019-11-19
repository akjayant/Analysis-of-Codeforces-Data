#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) cout<<#x<<" is "<<x<<endl;

const int maxn=1e6+5;

ll a[maxn];

int main(){
   // int t;
    //scanf("%d",&t);
   // while(t--){
        int n;
        scanf("%d",&n);
        ll sum=0;
        for(int i=1;i<=n;i++){scanf("%lld",&a[i]);sum+=a[i];}
        sort(a+1,a+1+n);
        if(n%2){
            ll x1,y1;
            x1=y1=0;
            for(int i=1;i<=n/2;i++){
                x1+=a[i];
            }
            ll x2=x1+a[n/2+1];
           // debug(x1);
            printf("%lld\n",max((x1*x1)+((sum-x1)*(sum-x1)),((x2*x2)+((sum-x2)*(sum-x2)))));
        }
        else{
            ll x1,y1;
            x1=y1=0;
            for(int i=1;i<=n/2;i++){
                x1+=a[i];
            }
            printf("%lld\n",(x1*x1)+((sum-x1)*(sum-x1)));
        }
   // }
    return 0;
}
