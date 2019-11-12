#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tt;
int n;
int a[1005];
// TabNine::config

int main(){
    scanf("%d",&tt);
    while(tt--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        int mx = 0;
        for(int i=1;i<=n;i++){
            mx = max(mx, min(i,a[i]));
        }
        printf("%d\n",mx);
    }


    

    return 0;
}