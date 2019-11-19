#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        long long A=0,B=0,Ans=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x%2)A++;
            else B++;
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            if(x%2)Ans+=A;
            else Ans+=B;
        }
        printf("%lld\n",Ans);
    }
    return 0;
}
