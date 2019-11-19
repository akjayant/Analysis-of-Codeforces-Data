#include<bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T; while(T--){
        int a,b,c,d,k;
        int x,y;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        x=a/c; if(a%c) x++;
        y=b/d; if(b%d) y++;
        if(x+y<=k) printf("%d %d\n",x,y);
        else printf("-1\n");
    }
}