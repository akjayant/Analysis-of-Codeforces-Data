#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        int t=min(b,c/2);
        ans+=3*t;
        b-=t;
        t=min(a,b/2);
        ans+=3*t;
        printf("%d\n",ans);
    }
    return 0;
}
