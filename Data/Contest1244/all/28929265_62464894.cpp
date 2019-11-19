#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;

int main() {
    int T,a,b,c,d,k;
    for(scanf("%d",&T);T;T--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int x = a/c+(a%c?1:0),y = b/d+(b%d?1:0);
        if(x+y>k) puts("-1");
        else printf("%d %d\n",x,k-x);
    }
    return 0;
}
