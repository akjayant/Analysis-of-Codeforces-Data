#include <bits/stdc++.h>
using namespace std;

int n;
int a,b,c,d,k;

int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int q=a/c;
        if(a%c) q++;
        int w=b/d;
        if(b%d) w++;
        if(q+w>k) printf("-1\n");
        else printf("%d %d\n",q,w);
    }
    return 0;
}
