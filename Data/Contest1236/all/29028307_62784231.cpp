#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c,t,ans;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&c); ans=0;
        ans+=3*min(b,c/2);
        b-=ans/3; c-=ans/3*2;
        ans+=3*min(a,b/2);
        printf("%d\n",ans);
    }
}