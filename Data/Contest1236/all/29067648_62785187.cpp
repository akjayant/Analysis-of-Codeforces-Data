#include<bits/stdc++.h>
using namespace std;
int n;
void work(){
    scanf("%d",&n);
    for(int i=1,a,b,c;i<=n;i++){
        scanf("%d%d%d",&a,&b,&c);
        int ans=min(c/2,b);
        b-=ans;ans*=3;
        ans+=3*min(b/2,a);
        printf("%d\n",ans);
    }

}
int main(){
    int t=1;//scanf("%d",&t);
    while(t--)work();
    return 0;
}
