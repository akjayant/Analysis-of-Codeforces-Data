#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) cout<<#x<<" is "<<x<<endl;

const int maxn=1e5+5;
const ll mod=1e9+7;

int a[maxn];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int ans=0;
        for(int i=n;i>=1;i--){
            if(a[i]>=(n-i+1)){
                ans=max(ans,(n-i+1));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
