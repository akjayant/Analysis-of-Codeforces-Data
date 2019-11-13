#include<bits/stdc++.h>

using namespace std;
const int N = 1234;
        int a[N];
int main(){

    int k;
    scanf("%d",&k);
    while(k--){
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n; i ++) scanf("%d",a+i);
        sort(a,a+n);
        int ans = 0;
        for(int i = 0 ; i < n; i ++){
            int len = min(a[i],n-i);
            if(ans < len){
                ans = len;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
