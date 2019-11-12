#include<bits/stdc++.h>
using namespace std;
int n,a[1007];
int cmp(int a,int b){
    return a>b;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=i){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}