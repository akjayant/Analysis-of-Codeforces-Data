#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int a,b,c;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        int x=c/2;
        int ans=0;
        x=min(x,b);
        b-=x;c-=2*x;
        ans+=3*x;
        x=b/2;
        x=min(x,a);
        ans+=3*x;
        printf("%d\n",ans);
    }
    return 0;
}