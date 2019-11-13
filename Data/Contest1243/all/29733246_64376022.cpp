#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000+50;

int T,n,a[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int ans=1;
        for(int i=n;i>=1;--i) {
            if (a[i] >= n-i+1) {
                ans=n-i+1;
            }
            else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}