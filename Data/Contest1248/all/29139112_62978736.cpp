#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) cout<<#x<<" is "<<x<<endl;

const int maxn=1e6+5;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        ll o,e;
        o=e=0;
        for(int i=1;i<=n;i++){
            ll a;
            scanf("%lld",&a);
            if(a%2)o++;
            else e++;
        }
        int m;
        scanf("%d",&m);
        ll o2,e2;
        o2=e2=0;
        for(int i=1;i<=m;i++){
            ll a;
            scanf("%lld",&a);
            if(a%2)o2++;
            else e2++;
        }
        printf("%lld\n",o*o2+e*e2);
    }
    return 0;
}
