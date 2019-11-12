#include<bits/stdc++.h>
using namespace std;
int t;
int a,b,c;
int main(){
    scanf("%d",&t);
    while(t--){
        int ans=0;
        scanf("%d%d%d",&a,&b,&c);
        ans+=min(b,c/2)*3;
        b-=c/2;
        b=max(b,0);
        ans+=min(a,b/2)*3;
        printf("%d\n",ans);
    }
}
